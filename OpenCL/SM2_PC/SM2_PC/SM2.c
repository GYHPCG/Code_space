/**
  ******************************************************************************
  * @FileName   : SM2.c
  * @Version    : v1.1
  * @Author     : FZM
  * @Date       : 2022-05-12
  * @Brief      : Fp域上的SM2加密、数字签名以及秘钥交换算法
  * @Caution	: 1.使用C99以上的C语言版本以支持任意位置定义变量
  *				  2.ECC.c中所有大数计算，都是把大数的高64bit放在num[3]，低64bit放在num[0]
  *					而转成字符串时要在ch[0]放num[3]的高8位
  *				  3.stm32需要勾选microlib以支持printf

  * @Attention  : 1.代码参考国家密码管理局《SM2椭圆曲线公钥密码算法》文档
  *				  2.函数传参时如果有变量Size必须注意是sizeInBit还是sizeInByte,
  *					这里我用的比较乱因为byte更易用，但是官方文档上用bit的地方代
  *					码会尊重官方，且同一个函数我不会以两种方式传参
  *				  3.倍点公式计算缓慢，可以优化算法
  *				  4.我单片机使用的Stack_Size      EQU     0x00006000
  *				                  Heap_Size       EQU     0x00009000
  * @Update		: V1.1	2022-5-12
  *						1.	之前有几处内存泄露，这里进行修改
  *						2.	有几个函数名字打错了，这里改掉
  *						3.	加了一组椭圆曲线推荐参数
  *						4.	取随机数算法，修改电脑和单片机上为两个版本，因为VS上的rand()函数返回15bit随机
  *							数，修改RAND_MAX为32位也没用。并把随机数种子刷新改为2个版本
  *						5.	对"ECC.c"中的modAdd()函数进行修改以保证两个加数之和大于p_mod的两倍时计算正确，
  *							上个版本的这个bug：由于数字签名算法中e+x1_可能超过n*2，所以按照原来的算法相加
  *							之后只对n作差一次的结果仍然大于n，导致算出的r modn>n(e是带公钥信息的哈希值所以
  *							不保证小于n)
  *				  V1.0	2022-5-10
  ******************************************************************************
  */
#include "SM2.h"

#ifdef USE_ON_STM32
#include "sys.h"
#else
#include "time.h"	//用于srand()
#endif

uint256_t UINT256_MAX = { 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff };

/**
  * 椭圆曲线的参数a b p
  * 基点G的坐标Gx,Gy，阶n
  * 使用时一定一定一定要记得把数组顺序反过来，
  * 就是现在的ellipticCurve_a[0]应该是a[3]，高位数据放在高地址。
  * 椭圆曲线初始化函数我会把a b p反过来，Gx,Gy可以初始化基点的时
  * 候自行赋值，而n我这里是每个用到的函数都写一个tmpN来赋值，属于自食其果，非常麻烦。
  * 但是建议不要把下面的值直接变换顺序，不然代码里可能会出问题，你的脑子会更乱。
  */
uint256_t ellipticCurve_a = { 0x787968B4FA32C3FD, 0x2417842E73BBFEFF, 0x2F3C848B6831D7E0, 0xEC65228B3937E498 };
uint256_t ellipticCurve_b = { 0x63E4C6D3B23B0C84, 0x9CF84241484BFE48, 0xF61D59A5B16BA06E, 0x6E12D1DA27C5249A };
uint256_t ellipticCurve_p = { 0x8542D69E4C044F18, 0xE8B92435BF6FF7DE, 0x457283915C45517D, 0x722EDB8B08F1DFC3 };
uint256_t ellipticCurve_n = { 0x8542D69E4C044F18, 0xE8B92435BF6FF7DD, 0x297720630485628D, 0x5AE74EE7C32E79B7 };
uint256_t ellipticCurve_Gx = { 0x421DEBD61B62EAB6, 0x746434EBC3CC315E, 0x32220B3BADD50BDC, 0x4C4E6C147FEDD43D };
uint256_t ellipticCurve_Gy = { 0x0680512BCBB42C07, 0xD47349D2153B70C4, 0xE5D7FDFCBFA36EA1, 0xA85841B9E46E09A2 };
/*国密SM2推荐参数*/
//uint256_t ellipticCurve_a = { 0xfffffffeffffffff, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF00000000, 0xFFFFFFFFFFFFFFFC };
//uint256_t ellipticCurve_b = { 0x28E9FA9E9D9F5E34, 0x4D5A9E4BCF6509A7, 0xF39789F515AB8F92, 0xDDBCBD414D940E93 };
//uint256_t ellipticCurve_p = { 0xFFFFFFFEFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF00000000, 0xffffffffffffffff };
//uint256_t ellipticCurve_n = { 0xfffffffeffffffff, 0xFFFFFFFFFFFFFFFF, 0x7203DF6B21C6052B, 0x53BBF40939D54123 };
//uint256_t ellipticCurve_Gx = { 0x32C4AE2C1F198119, 0x5F9904466A39C994, 0x8FE30BBFF2660BE1, 0x715A4589334C74C7 };
//uint256_t ellipticCurve_Gy = { 0xBC3736A2F4F6779C, 0x59BDCEE36B692153, 0xD0A9877CC62A4740, 0x02DF32E52139F0A0 };

/*examples, for DEBUG ONLY!!!*/
//exampe for SM2encrypt
//uint256_t exPrivateKey = { 0x1649AB77A00637BD, 0x5E2EFE283FBF3535, 0x34AA7F7CB89463F2, 0x08DDBC2920BB0DA0 };
//uint256_t exRandomK = { 0x4C62EEFD6ECFC2B9, 0x5B92FD6C3D957514, 0x8AFA17425546D490, 0x18E5388D49DD7B4F };
//exampe for SM2sign
uint256_t exPrivateKey = { 0x128B2FA8BD433C6C, 0x068C8D803DFF7979, 0x2A519A55171B1B65, 0x0C23661D15897263 };
uint256_t exRandomK = { 0x6CB28D99385C175C ,0x94F94E934817663F ,0xC176D925DD72B727 ,0x260DBAAE1FB2F96F };
//example for SM2exchange
uint256_t exPrivateKey_A = { 0x6FCBA2EF9AE0AB90, 0x2BC3BDE3FF915D44, 0xBA4CC78F88E2F8E7, 0xF8996D3B8CCEEDEE };
uint256_t exPrivateKey_B = { 0x5E35D7D3F3C54DBA, 0xC72E61819E730B01, 0x9A84208CA3A35E4C, 0x2E353DFCCB2A3B53 };
uint256_t exRandom_rA = { 0x83A2C9C8B96E5AF7, 0x0BD480B472409A9A, 0x327257F1EBB73F5B, 0x073354B248668563 };
uint256_t exRandom_rB = { 0x33FE21940342161C, 0x55619C4A0C060293, 0xD543C80AF19748CE, 0x176D83477DE71C80 };
uint256_t exPublicKey_Ax = { 0x3099093BF3C137D8, 0xFCBBCDF4A2AE50F3, 0xB0F216C3122D7942, 0x5FE03A45DBFE1655 };
uint256_t exPublicKey_Ay = { 0x3DF79E8DAC1CF0EC, 0xBAA2F2B49D51A4B3, 0x87F2EFAF48233908, 0x6A27A8E05BAED98B };
uint256_t exPublicKey_Bx = { 0x245493D446C38D8C, 0xC0F118374690E7DF, 0x633A8A4BFB3329B5, 0xECE604B2B4F37F43 };
uint256_t exPublicKey_By = { 0x53C0869F4B9E1777, 0x3DE68FEC45E14904, 0xE0DEA45BF6CECF99, 0x18C85EA047C60A4C };

EllipticCurveDef Ec[1];	//生成的椭圆曲线
EccPoint pointZero = { {0, 0, 0, 0}, {0, 0, 0, 0} };	//零点
extern EccPoint G[1];
extern uint8_t C[505];
/**
  * @name    EllipticCurveInit
  * @brief   初始化一个椭圆曲线，这里的椭圆曲线EC放在全局变量
  * @param   a
  * @param   b
  * @param   p
  * @author  FZM
  * @date    2022-05-06 13:55:15
  */
void EllipticCurveInit(uint64_t* a, uint64_t* b, uint64_t* p)
{
    //Ec = malloc(sizeof(EllipticCurveDef));
    for (int i = 0; i < 4; i++)
    {
        Ec->a[i] = a[3 - i];
        Ec->b[i] = b[3 - i];
        Ec->p[i] = p[3 - i];
    }
}

/**
  * @name    IsValidPoint
  * @brief   判断point点是否在椭圆曲线EC上
  * @param   point	待判断的点
  * @param   Ec	所用的椭圆曲线
  * @retval  BOOL
  * @author  FZM
  * @date    2022-05-06 13:54:51
  */
BOOL IsValidPoint(EccPoint* point, EllipticCurveDef* Ec)
{
    uint64_t* left = (uint64_t*)malloc(sizeof(uint64_t) * 4),
        * right = (uint64_t*)malloc(sizeof(uint64_t) * 4),
        * tmpRight = (uint64_t*)malloc(sizeof(uint64_t) * 4);

    vli_modMult(left, point->y, point->y, Ec->p);		//left = y^2
    vli_modMult(tmpRight, point->x, point->x, Ec->p);
    vli_modMult(right, tmpRight, point->x, Ec->p);		//x^3
    vli_modMult(tmpRight, Ec->a, point->x, Ec->p);		//a*x
    vli_modAdd(tmpRight, right, tmpRight, Ec->p);		//x^3 + a*x
    vli_modAdd(right, tmpRight, Ec->b, Ec->p);			//right = x^3 + a*x + b

    int res = vli_cmp(left, right);
    free(left);
    free(right);
    free(tmpRight);

    return !res;
}

/**
  * @name    GetRandomNumber
  * @brief   获得一个uint256_t随机数,因为SM2要求maxVal的最高DWORD必须有值，
  *			 所以我这里直接令result[3] %= (maxVal[3]-1)保证结果小于maxVal
  * @param   result 为获取到的随机数
  * @author  FZM
  * @date    2022-05-08 02:42:59
  */
void GetRandomNumber(uint64_t* result, uint64_t* maxVal)
{
#ifndef DEBUG_MODE
#ifndef USE_ON_STM32
    srand(clock());
#else
    SysTick->LOAD = 0xffffffff;	//Systick->val作为随机数种子
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    uint32_t val = SysTick->VAL;
    srand(val);
#endif	//USE_ON_STM32
#endif	//DEBUG_MODE

    for (int i = 0; i < 4; i++)
    {
#ifdef USE_ON_STM32
        result[i] = ((uint64_t)rand() << 62) | ((uint64_t)rand() << 31) | rand();
#else
        result[i] = ((uint64_t)rand() << 60) | ((uint64_t)rand() << 45) | ((uint64_t)rand() << 30) | ((uint64_t)rand() << 15) | ((uint64_t)rand() << 0);//电脑上的rand()函数返回16bit随机数，修改RAND_MAX无效
#endif
    }
    //int tmp = GetMSB(maxVal);
    //Uint256WriteBits(result, 0, tmp, 255);
    result[3] %= (maxVal[3] - 1);
}

/**
  * @name    IsZeroPoint
  * @brief   判断一点是否为零点
  * @param   point
  * @retval  BOOL
  * @author  FZM
  * @date    2022-05-08 02:43:36
  */
BOOL IsZeroPoint(EccPoint* point)
{
    for (int i = 0; i < 4; i++)
    {
        if (point->x[i])
        {
            return 0;
        }
        if (point->y[i])
        {
            return 0;
        }
    }

    return 1;
}

/**
  * @name    IsZeroUint256
  * @brief   判断一个uint256_t数是否为0
  * @param   bigNum
  * @retval  BOOL
  * @author  FZM
  * @date    2022-05-08 02:44:00
  */
BOOL IsZeroUint256(uint64_t* num)
{
    for (int i = 0; i < 4; i++)
    {
        if (num[i])
        {
            return 0;
        }
    }

    return 1;
}

/**
  * @name    GenerateKeys
  * @brief   产生公钥及私钥
  * @param   privKey 返回私钥
  * @param   pubKey	返回公钥
  * @param   pointG	基点G
  * @retval  BOOL 是否成功
  * @author  FZM
  * @date    2022-05-08 02:45:32
  */
BOOL GenerateKeys(uint64_t* privKey, EccPoint* pubKey, EccPoint* pointG)
{
    int maxTries = 16;

    uint256_t tmp = { 0 };
    for (int i = 0; i < 4; i++)
    {
        tmp[i] = ellipticCurve_n[3 - i];
    }
    do {
        maxTries--;
        if (maxTries == 0)
        {
            return FALSE;
        }
        GetRandomNumber(privKey, Ec->p);
#ifdef DEBUG_MODE
        for (int i = 0; i < 4; i++)//方便测试所以固定随机数
        {
            privKey[i] = exPrivateKey[3 - i];
        }
#endif
        if (IsZeroUint256(privKey))
        {
            continue;
        }
        if (vli_cmp(tmp, privKey) != 1)	//Make sure that privKey is < n
        {
            vli_sub(privKey, privKey, tmp);
        }
        CurvePointMul(pubKey, pointG, privKey);
    } while (IsZeroPoint(pubKey));

    return TRUE;
}

/**
  * @name    CurvePointAdd
  * @brief   椭圆曲线上两点相加
  * @param   res	返回相加的结果点
  * @param   p1
  * @param   p2
  * @author  FZM
  * @date    2022-05-08 02:46:24
  */
void CurvePointAdd(EccPoint* res, EccPoint* p1, EccPoint* p2)
{
    uint256_t tmp1 = { 0 }, tmp2 = { 0 }, k = { 0 }, k2 = { 0 },
        num2 = { {2},{0},{0},{0} }, num3 = { {3},{0},{0},{0} };
    int i = 0;

    if (IsZeroPoint(p2))
    {
        for (i = 0; i < 4; i++)
        {
            res->x[i] = p1->x[i];
            res->y[i] = p1->y[i];
        }
        return;
    }
    if (IsZeroPoint(p1))
    {
        for (i = 0; i < 4; i++)
        {
            res->x[i] = p2->x[i];
            res->y[i] = p2->y[i];
        }
        return;
    }
    for (i = 0; i < 4; i++)
    {
        if (p1->x[i] != p2->x[i])
        {
            break;
        }
    }
    if (i == 4)	//两点重合
    {
        vli_modMult(tmp1, p1->x, p1->x, Ec->p);//tmp1 = x1^2
        vli_modMult(tmp1, num3, tmp1, Ec->p);//tmp1 = 3*x1^2
        vli_modAdd(tmp1, tmp1, Ec->a, Ec->p);//tmp1 = 3*x1^2+a
        vli_modMult(tmp2, num2, p2->y, Ec->p);//tmp2 = 2*y1
        vli_modInv(k, tmp2, Ec->p);	//k = 1/(2*y1)
        vli_modMult(k, k, tmp1, Ec->p);//k = (3*x1^2+a)/(2*y1)
        vli_modMult(k2, k, k, Ec->p);//k2 = k^2
        vli_modAdd(tmp1, p1->x, p2->x, Ec->p);//tmp1 = x1+x2
        vli_modSub(tmp2, k2, tmp1, Ec->p);//tmp2 = x3 = x4

        vli_modSub(tmp1, p1->x, tmp2, Ec->p);//tmp1 = x1 - x3
        vli_modMult(tmp1, k, tmp1, Ec->p);//tmp1 = k(x1-x3)
        vli_modSub(tmp1, tmp1, p1->y, Ec->p);//tmp1 = y4
    }
    else
    {
        vli_modSub(tmp1, p1->x, p2->x, Ec->p);//tmp1 = x1-x2
        vli_modSub(tmp2, p1->y, p2->y, Ec->p);//tmp2 = y1-y2
        vli_modInv(k, tmp1, Ec->p);	//k = 1/(x1-x2)
        vli_modMult(k, k, tmp2, Ec->p);//k = (y1-y2)/(x1-x2)
        vli_modMult(k2, k, k, Ec->p);//k2 = k^2
        vli_modAdd(tmp1, p1->x, p2->x, Ec->p);//tmp1 = x1+x2
        vli_modSub(tmp2, k2, tmp1, Ec->p);//tmp2 = x3 = x4

        vli_modSub(tmp1, p1->x, tmp2, Ec->p);//tmp1 = x1 - x3
        vli_modMult(tmp1, k, tmp1, Ec->p);//tmp1 = k(x1-x3)
        vli_modSub(tmp1, tmp1, p1->y, Ec->p);//tmp1 = y4
    }
    for (i = 0; i < 4; i++)
    {
        res->x[i] = tmp2[i];
        res->y[i] = tmp1[i];
    }
}

/**
  * @name    Uint256BitShift
  * @brief   uint256_t数左移/右移
  * @param   num
  * @param   shift	左移的位数(<0则右移)
  * @author  FZM
  * @date    2022-05-08 02:47:29
  */
void Uint256BitShift(uint64_t* num, int shift)
{
    if (shift < 0)
    {
        while (shift++)
        {
            num[0] = (num[0] >> 1) | ((num[1] & 1ULL) << 63);
            num[1] = (num[1] >> 1) | ((num[2] & 1ULL) << 63);
            num[2] = (num[2] >> 1) | ((num[3] & 1ULL) << 63);
            num[3] = num[3] >> 1;
        }
    }
    else if (shift > 0)
    {
        while (shift--)
        {
            num[3] = (num[3] << 1) | ((num[2] & (1ULL << 63)) >> 63);
            num[2] = (num[2] << 1) | ((num[1] & (1ULL << 63)) >> 63);
            num[1] = (num[1] << 1) | ((num[0] & (1ULL << 63)) >> 63);
            num[2] = (num[0] << 1);
        }
    }
}

/**
  * @name    BigBitShift
  * @brief   大数左移/右移1位
  * @param   num
  * @param   shift	>0左移1位,<0右移1位
  * @author  FZM
  * @date    2022-05-08 02:47:29
  */
//void BigBitShift(BIG* num, BOOL shift)
//{
//    num->data = malloc(sizeof(uint64_t) * (num->sizeInLongLong + 1));
//    if (shift == 0)
//    {
//        if (num->data[num->sizeInLongLong - 1] == 1ULL)
//        {
//            num->sizeInLongLong = num->sizeInLongLong - 1;
//        }
//        for (int64_t i = 0; i < num->sizeInLongLong; i++)
//        {
//            num->data[i] = (num->data[i] >> 1) |
//                (i + 1 < num->sizeInLongLong ? ((num->data[i + 1] & 1ULL) << 63) : 0);
//        }
//    }
//    else if (shift > 0)
//    {
//        if (num->data[num->sizeInLongLong - 1] & (0x8000000000000000ULL))
//        {
//            num->data[num->sizeInLongLong] = 1;
//            num->sizeInLongLong = num->sizeInLongLong + 1;
//        }
//        for (int64_t i = num->sizeInLongLong - 1; i >= 0; i--)
//        {
//            num->data[i] = (num->data[i] << 1) |
//                (i - 1 >= 0 ? ((num->data[i - 1] & 0x8000000000000000ULL) >> 63) : 0);
//        }
//    }
//}


void Uint256Cpy(uint64_t* des, uint64_t* src)
{
    for (int i = 0; i < 4; i++)
    {
        des[i] = src[i];
    }
}

/**
  * @name    CurvePointMul
  * @brief   倍点
  * @param   res	返回结果
  * @param   p1		待乘点
  * @param   times	乘数
  * @author  FZM
  * @date    2022-05-08 02:49:30
  */
void CurvePointMul(EccPoint* res, EccPoint* p1, uint64_t* times)
{
    EccPoint* tmpPoint = malloc(sizeof(EccPoint)), * tmpPoint1 = malloc(sizeof(EccPoint));
    uint64_t* tmpTimes = malloc(sizeof(EccPoint));

    Uint256Cpy(tmpPoint->x, p1->x);
    Uint256Cpy(tmpPoint->y, p1->y);
    Uint256Cpy(tmpTimes, times);

    for (int i = 0; i < 4; i++)
    {
        res->x[i] = 0;
        res->y[i] = 0;
    }
    while (!IsZeroUint256(tmpTimes))
    {
        if (tmpTimes[0] & 0x1)
        {
            CurvePointAdd(res, res, tmpPoint);		//res = res + tmpPoint
        }
        Uint256BitShift(tmpTimes, -1);	//times >>= 1
        Uint256Cpy(tmpPoint1->x, tmpPoint->x);
        Uint256Cpy(tmpPoint1->y, tmpPoint->y);
        CurvePointAdd(tmpPoint, tmpPoint, tmpPoint1);	//tmpPoint *= 2
    }
    free(tmpPoint);
    free(tmpPoint1);
    free(tmpTimes);
}

/**
  * @name    Uint256ToString
  * @brief   uint256_t转char*，num[3] 放在 res[0]~res[3],注意
  *		     为了防止内存访问越界这里没有添加'\0'，所以不是真正意义上的字符串
  * @param   res
  * @param   num
  * @author  FZM
  * @date    2022-05-08 02:50:35
  */
void Uint256ToString(uint8_t* res, uint256_t num)
{
    int  pos = 0;

    for (int i = 3; i >= 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            res[pos++] = (num[i] & (0xffULL << (j * 8))) >> (j * 8);
        }
    }
}

/**
  * @name    StringToUint256
  * @brief   char*转uint256_t，res[3]存放num[0]~num[3]
  * @param   res
  * @param   num
  * @author  FZM
  * @date    2022-05-08 02:50:35
  */
void StringToUint256(uint64_t* res, uint8_t* num)
{
    int  pos = 0;

    memset(res, 0, 32);
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            uint64_t tmp = 0xff & (uint64_t)num[pos++];
            res[i] |= tmp << (j * 8);
        }
    }
}

/**
  * @name    SM2Encrypt
  * @brief   SM2加密,返回C = C1 || C2 || C3
  * @param   messagePlain	待加密的明文字符串
  * @param   messageSizeInBit	字符串比特数(len*8)
  * @param   pubKey	公钥
  * @retval  char* C
  * @author  FZM
  * @date    2022-05-08 02:53:46
  */

uint8_t* SM2Encrypt(char* messagePlain, int messageSizeInBit, EccPoint* pubKey)
{
    uint256_t randomK = { 0 };
    printf("message is %d\n", messageSizeInBit);
    printf("uint_8 is %d\n", sizeof(uint8_t));
    //EccPoint* pointC1 = malloc(sizeof(EccPoint)), * kPb = malloc(sizeof(EccPoint));
    //uint8_t* t = malloc(messageSizeInBit / 8), * x2 = malloc(64), * y2 = malloc(32),//t = KDF()
    //    * C1 = malloc(65), * x1 = malloc(32), * y1 = malloc(32),
    //    * C2 = malloc(messageSizeInBit / 8), * C3 = malloc(64 + messageSizeInBit / 8),
    //    * C = malloc(65 + messageSizeInBit / 8 + 32);

    EccPoint pointC1[1], kPb[1];
    uint8_t t[408], x2[64], y2[32], C1[65], x1[32], y1[32], C2[408], C3[472];
        //C[505];
    GetRandomNumber(randomK, Ec->p);
#ifdef DEBUG_MODE
    for (int i = 0; i < 4; i++)	//测试时随机数先固定
    {
        randomK[i] = exRandomK[3 - i];
    }
#endif
    CalculateC1(pointC1, randomK, G);
    Uint256ToString(x1, pointC1->x);
    Uint256ToString(y1, pointC1->y);
    C1[0] = 0x04;
    memcpy(C1 + 1, x1, 32);
    memcpy(C1 + 33, y1, 32);//C1 = 04||x1||y1

    CalculateKPb(kPb, randomK, pubKey);
    Uint256ToString(x2, kPb->x);
    Uint256ToString(y2, kPb->y);

    memcpy(C3, x2, 32);
    memcpy(C3 + 32, messagePlain, messageSizeInBit / 8);
    memcpy(C3 + 32 + messageSizeInBit / 8, y2, 32);

    memcpy(x2 + 32, y2, 32);//x2 = x2 || y2
    KDF(t, x2, 64 * 8, messageSizeInBit);	//t = KDF()
    CalculateC2(C2, messagePlain, t, messageSizeInBit / 8);	//C2 = M^t
    SM3((uint8_t*)C3, 64 + messageSizeInBit / 8, (uint8_t*)C3);	//C3 = SM3(x2||M||y2)

    memcpy(C, C1, 65);
    memcpy(C + 65, C2, messageSizeInBit / 8);
    memcpy(C + 65 + messageSizeInBit / 8, C3, 32);	//C = C1 || C2 || C3
   /* free(pointC1);
    free(kPb);*/
    /*free(t);
    free(x2);
    free(y2);
    free(C1);
    free(x1);
    free(y1);
    free(C2);
    free(C3);*/

    return C;
}

/**
  * @name    CalculateC1
  * @brief   计算C1 = kG
  * @param   result
  * @param   k
  * @param   G
  * @author  FZM
  * @date    2022-05-08 02:55:36
  */
void CalculateC1(EccPoint* result, uint256_t k, EccPoint* G)
{
    CurvePointMul(result, G, k);
}

/**
  * @name    CalculateKPb
  * @brief   计算k * PB
  * @param   result
  * @param   k
  * @param   Pb
  * @author  FZM
  * @date    2022-05-08 02:55:59
  */
void CalculateKPb(EccPoint* result, uint256_t k, EccPoint* Pb)
{
    CurvePointMul(result, Pb, k);
}

/**
  * @name    CalculateC2
  * @brief   计算C2 = M ^ t
  * @param   result
  * @param   M
  * @param   t
  * @param   lenInByte
  * @author  FZM
  * @date    2022-05-08 02:56:22
  */
void CalculateC2(uint8_t* result, char* M, uint8_t* t, int lenInByte)
{
    for (int i = 0; i < lenInByte; i++)
    {
        result[i] = M[i] ^ t[i];
    }
}

/**
  * @name    KDF
  * @brief   秘钥派生函数key derivation function
  * @param   result	计算结果，申请空间至少(keyLenInBit/8) Bytes
  * @param   Z 用于计算的比特串Z
  * @param   dataLenInBit Z的比特长度
  * @param   keyLenInBit 协商好的生成的秘钥比特长度,SM2中应该和message长度相同
  * @author  FZM
  * @date    2022-05-08 02:56:43
  */
void KDF(uint8_t* result, uint8_t* Z, int dataLenInBit, int keyLenInBit)
{
    uint8_t* tmpRes = (uint8_t*)malloc(keyLenInBit / 8), * tmpData = (uint8_t*)malloc(dataLenInBit / 8 + 4);

    keyLenInBit /= 8;
    dataLenInBit /= 8;//转为byte数
    memset(tmpRes, 0, keyLenInBit);
    memset(tmpData, 0, dataLenInBit + 4);

    uint32_t ct = 1;  //a.初始化32bit计数器
    uint8_t hash[32] = { 0 }, ct2Byte[4] = { 0 }; //ct2Byte与计数器的值一样,只是为了方便计算
    int realHashLen = 32; //摘要长度
    int maxLoopNum = (keyLenInBit + 31) / 32; //times = [klenInBit/v](向上取整)
    int i = 0;

    memcpy(tmpData, Z, dataLenInBit);
    for (i = 0; i < maxLoopNum; i++)
    {
        ct2Byte[0] = (ct >> 24) & 0xFF;
        ct2Byte[1] = (ct >> 16) & 0xFF;
        ct2Byte[2] = (ct >> 8) & 0xFF;
        ct2Byte[3] = (ct) & 0xFF;
        memcpy(tmpData + dataLenInBit, ct2Byte, 4);	// Z || ct
        SM3(tmpData, dataLenInBit + 4, hash);	//b. 计算Hai = Hv(Z || ct)

        if (i == maxLoopNum - 1) //c. 根据keylen/32是否整除，截取摘要的值
        {
            if (keyLenInBit % 32 != 0)
            {
                realHashLen = keyLenInBit % 32;
            }
        }
        memcpy(tmpRes + 32 * i, hash, realHashLen);	//d. 每次把结果连接上
        //i++;
        ct++;
    }

    if (result != NULL)
    {
        memcpy(result, tmpRes, keyLenInBit);
    }
    free(tmpRes);
    free(tmpData);
}

/**
  * @name    SM2Decrypt
  * @brief   SM2解密
  * @param   C	密文
  * @param   lenInByte	C的字节数
  * @param   privKey	私钥
  * @retval  char* 	解密出的明文
  * @author  FZM
  * @date    2022-05-08 02:57:30
  */
uint8_t* SM2Decrypt(char* C, int lenInByte, uint64_t* privKey)
{
    EccPoint* pointC1 = malloc(sizeof(EccPoint)), * point2 = malloc(sizeof(EccPoint));
    int lenOfMsg = lenInByte - 65 - 32;
    uint8_t* C2 = malloc(lenOfMsg + 1), * msg = malloc(lenOfMsg + 1),
        * x1 = malloc(32), * y1 = malloc(32),
        * x2 = malloc(64), * y2 = malloc(32), * t = malloc(lenOfMsg);

    msg[lenInByte - 65 - 32] = '\0';
    memcpy(C2, C + 65, lenInByte - 65 - 32);//密文msg
    memcpy(x1, C + 1, 32);
    memcpy(y1, C + 1 + 32, 32);
    StringToUint256(pointC1->x, x1);
    StringToUint256(pointC1->y, y1);
    CurvePointMul(point2, pointC1, privKey);
    Uint256ToString(x2, point2->x);
    Uint256ToString(y2, point2->y);
    memcpy(x2 + 32, y2, 32);	//x2 = x2 || y2
    KDF(t, x2, 64 * 8, (lenInByte - 65 - 32) * 8);//t = KDF(x2||y2,klenInBit)
    CalculateMessage(msg, C2, t, lenOfMsg);	//M' = C2 ^ t
    free(pointC1);
    free(point2);
    free(C2);
    free(x1);
    free(y1);
    free(x2);
    free(y2);
    free(t);

    return msg;
}

/**
  * @name    CalculateMessage
  * @brief   计算明文M' = C2 ^ t
  * @param   result	M'
  * @param   C2
  * @param   t
  * @param   lenInByte
  * @author  FZM
  * @date    2022-05-08 02:58:32
  */
void CalculateMessage(uint8_t* result, uint8_t* C2, uint8_t* t, int lenInByte)
{
    for (int i = 0; i < lenInByte; i++)
    {
        result[i] = C2[i] ^ t[i];
    }
}


/**
  * @name    SM2Sign
  * @brief   SM2数字签名算法
  * @param   message 待签名的消息
  * @param   messageSizeInBit 待签名消息的比特长度
  * @param   IDA	用户A(签名者)的身份
  * @param   ENTLAInBit	用户A的身份的比特数
  * @param   G	基点
  * @param   pubKey	公钥
  * @param   privKey	私钥
  * @retval  SM2Signature* 包含(r,s)的数字签名
  * @author  FZM
  * @date    2022-05-09 20:15:59
  */
SM2Signature* SM2Sign(char* message, int messageSizeInBit, char* IDA, uint16_t ENTLAInBit, EccPoint* G, EccPoint* pubKey, uint64_t* privKey)
{
    //ZA = SM3(ENT LA ∥ IDA ∥ a ∥ b ∥ xG ∥ yG ∥ xA ∥ yA)。
    uint8_t* Z = malloc(2 + ENTLAInBit / 8 + 32 + 32 + 32 + 32 + 32 + 32), * ZA = malloc(32);
    uint256_t tmpN = { 0 };
    SM2Signature* result = malloc(sizeof(SM2Signature));

    for (int i = 0; i < 4; i++)
    {
        tmpN[i] = ellipticCurve_n[3 - i];
    }
    Z[0] = ENTLAInBit >> 8;
    Z[1] = ENTLAInBit & 0xff;
    memcpy(Z + 2, IDA, ENTLAInBit / 8);
    Uint256ToString(ZA, Ec->a);
    memcpy(Z + 2 + ENTLAInBit / 8, ZA, 32);
    Uint256ToString(ZA, Ec->b);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32, ZA, 32);
    Uint256ToString(ZA, G->x);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 2, ZA, 32);
    Uint256ToString(ZA, G->y);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 3, ZA, 32);
    Uint256ToString(ZA, pubKey->x);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 4, ZA, 32);
    Uint256ToString(ZA, pubKey->y);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 5, ZA, 32);
    SM3(Z, 2 + ENTLAInBit / 8 + 32 + 32 + 32 + 32 + 32 + 32, ZA);//ZA = SM3(ENT LA ∥ IDA ∥ a ∥ b ∥ xG ∥ yG ∥ xA ∥ yA)。
    free(Z);

    uint8_t* M_ = malloc(messageSizeInBit / 8 + 32), * e = malloc(32);
    memcpy(M_, ZA, 32);
    memcpy(M_ + 32, message, messageSizeInBit / 8);
    SM3(M_, messageSizeInBit / 8 + 32, e);	//e = H256(M_)：
    free(M_);

    uint8_t* x1 = malloc(32), * y1 = malloc(32), * r = malloc(32), * s = malloc(32);
    uint256_t randomK = { 0 }, tmpE = { 0 }, tmpX = { 0 }, tmpR = { 0 }, num1 = { 1 };
    EccPoint* point1 = malloc(sizeof(EccPoint));
    GetRandomNumber(randomK, tmpN);
#ifdef DEBUG_MODE
    for (int i = 0; i < 4; i++)	//测试时随机数先固定
    {
        randomK[i] = exRandomK[3 - i];
    }
#endif

    CurvePointMul(point1, G, randomK);
    Uint256ToString(x1, point1->x);
    Uint256ToString(y1, point1->y);
    free(point1);
    StringToUint256(tmpE, e);
    StringToUint256(tmpX, x1);
    vli_modAdd(tmpR, tmpE, tmpX, tmpN);
    Uint256ToString(r, tmpR);	//r=(e+x1) modn

    vli_modAdd(tmpE, num1, privKey, tmpN);
    vli_modInv(tmpX, tmpE, tmpN);	//(1+dA)^-1
    vli_modMult(tmpE, tmpR, privKey, tmpN);
    vli_modSub(tmpE, randomK, tmpE, tmpN);
    vli_modMult(tmpX, tmpX, tmpE, tmpN);
    Uint256ToString(s, tmpX);	//s = ((1+dA)^-1 * (k - r*dA))modn
    memcpy(result->r, r, 32);
    memcpy(result->s, s, 32);
    free(ZA);
    free(e);
    free(x1);
    free(y1);
    free(r);
    free(s);

    return result;
}


/**
  * @name    SM2SignatureVerify
  * @brief   SM数字签名校验
  * @param   message	M'用户B(验证者)即收到的消息
  * @param   messageSizeInBit	M'的比特大小
  * @param   sign	(r,s)
  * @param   IDA	用户A的身份
  * @param   ENTLAInBit		用户A的身份的比特大小
  * @param   G	基点
  * @param   pubKey	公钥
  * @retval  BOOL 	验证成功/失败
  * @author  FZM
  * @date    2022-05-10 09:36:52
  */
BOOL SM2SignatureVerify(char* message, int messageSizeInBit, SM2Signature* sign, char* IDA, uint16_t ENTLAInBit, EccPoint* G, EccPoint* pubKey)
{
    uint256_t tmp = { 0 }, tmpN = { 0 }, num1 = { 1 };

    for (int i = 0; i < 4; i++)
    {
        tmpN[i] = ellipticCurve_n[3 - i];
    }
    vli_modSub(tmpN, tmpN, num1, Ec->p);	//因为n是大质数必定为奇数，所以这里可以直接n[0] = n[0] - 1，不必像我这样写
    StringToUint256(tmp, sign->r);
    if (IsZeroUint256(tmp) || vli_cmp(tmp, tmpN) >= 0)	//make sure r∈[1,n-1]
    {
        return FALSE;
    }
    StringToUint256(tmp, sign->s);
    if (IsZeroUint256(tmp) || vli_cmp(tmp, tmpN) >= 0)	//make sure s∈[1,n-1]
    {
        return FALSE;
    }
    vli_modAdd(tmpN, tmpN, num1, Ec->p);

    //ZA = SM3(ENT LA ∥ IDA ∥ a ∥ b ∥ xG ∥ yG ∥ xA ∥ yA)。
    uint8_t* Z = malloc(2 + ENTLAInBit / 8 + 32 + 32 + 32 + 32 + 32 + 32), * ZA = malloc(32);

    Z[0] = ENTLAInBit >> 8;
    Z[1] = ENTLAInBit & 0xff;
    memcpy(Z + 2, IDA, ENTLAInBit / 8);
    Uint256ToString(ZA, Ec->a);
    memcpy(Z + 2 + ENTLAInBit / 8, ZA, 32);
    Uint256ToString(ZA, Ec->b);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32, ZA, 32);
    Uint256ToString(ZA, G->x);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 2, ZA, 32);
    Uint256ToString(ZA, G->y);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 3, ZA, 32);
    Uint256ToString(ZA, pubKey->x);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 4, ZA, 32);
    Uint256ToString(ZA, pubKey->y);
    memcpy(Z + 2 + ENTLAInBit / 8 + 32 * 5, ZA, 32);
    SM3(Z, 2 + ENTLAInBit / 8 + 32 + 32 + 32 + 32 + 32 + 32, ZA);//ZA = SM3(ENT LA ∥ IDA ∥ a ∥ b ∥ xG ∥ yG ∥ xA ∥ yA)。
    free(Z);

    uint8_t* M_ = malloc(messageSizeInBit / 8 + 32), * e = malloc(32);
    memcpy(M_, ZA, 32);
    memcpy(M_ + 32, message, messageSizeInBit / 8);
    SM3(M_, messageSizeInBit / 8 + 32, e);	//e=H256(M_)：
    free(M_);

    uint256_t tmpR = { 0 }, tmpS = { 0 }, tmpT = { 0 };

    StringToUint256(tmpR, sign->r);
    StringToUint256(tmpS, sign->s);
    vli_modAdd(tmpT, tmpR, tmpS, tmpN);	//t = (r' + s')modn

    EccPoint* point0 = malloc(sizeof(EccPoint)), * point00 = malloc(sizeof(EccPoint)),
        * point1 = malloc(sizeof(EccPoint));

    CurvePointMul(point0, G, tmpS);	//point0 = s' * G
    CurvePointMul(point00, pubKey, tmpT);	//point00 = t * PA
    CurvePointAdd(point1, point0, point00);	//point1 = s'*G+t*PA
    free(point0);
    free(point00);

    uint8_t* r = malloc(32);
    StringToUint256(tmpT, e);	//只是把e存在tmpT里
    vli_modAdd(tmpR, tmpT, point1->x, tmpN);
    Uint256ToString(r, tmpR);
    free(ZA);
    free(e);
    free(point1);

    for (int i = 0; i < 32; i++)
    {
        if (r[i] != sign->r[i])
        {
            free(r);
            return FALSE;
        }
    }
    free(r);
    return TRUE;
}

/**
  * @name    SM2KeyExchange
  * @brief   SM2秘钥交换协议
  * @param   IDA	用户A的身份
  * @param   ENTLAInBit	用户A的身份比特长度
  * @param   IDB	用户B的身份
  * @param   ENTLBInBit	用户B的身份比特长度
  * @param   G	基点
  * @param   klenInBit	表示要获得的密钥数据的比特长度
  * @retval  BOOL 协商成功/失败
  * @author  FZM
  * @date    2022-05-09 20:27:36
  * @attention 此函数以及调用的函数和变量命名均参考国家密码
  *  		   管理局《SM2椭圆曲线公钥密码算法》中的第三部分
  *			   秘钥交换协议。所有变量及函数命名不再加以注释
  */
BOOL KeyExchangeCheck = TRUE;//可选项，是否要验证S2 == SA以及S1 == SB
BOOL SM2KeyExchange(char* IDA, uint32_t ENTLAInBit, char* IDB, uint32_t ENTLBInBit, EccPoint* G, int klenInBit)
{
    EccPoint* RA = malloc(sizeof(EccPoint)), * V = malloc(sizeof(EccPoint)),
        * U = malloc(sizeof(EccPoint)),
        * pubKeyA = malloc(sizeof(EccPoint)), * pubKeyB = malloc(sizeof(EccPoint)),
        * RB = malloc(sizeof(EccPoint));
    uint256_t tB = { 0 }, privKeyA = { 0 }, privKeyB = { 0 };
    uint8_t* tmp = malloc(2 + ENTLAInBit / 8 + 32 * 6), * tmp1 = malloc(32);//用来算ZA ZB

    GenerateKeys(privKeyA, pubKeyA, G);
    GenerateKeys(privKeyB, pubKeyB, G);
    if (!(IsValidPoint(pubKeyA, Ec) && IsValidPoint(pubKeyB, Ec)))
    {
        return FALSE;
    }

#ifdef DEBUG_MODE
    for (int i = 0; i < 4; i++)	//测试固定随机数
    {
        privKeyA[i] = exPrivateKey_A[3 - i];
        privKeyB[i] = exPrivateKey_B[3 - i];
        pubKeyA->x[i] = exPublicKey_Ax[3 - i];
        pubKeyA->y[i] = exPublicKey_Ay[3 - i];
        pubKeyB->x[i] = exPublicKey_Bx[3 - i];
        pubKeyB->y[i] = exPublicKey_By[3 - i];
    }
#endif
    //双方的原始数据
    KeyExchangeAOriginalInfoDef infoA =
    { {0},{0},privKeyA[0],privKeyA[1],privKeyA[2],privKeyA[3],pubKeyA,pubKeyB,0,1,{0},G };
    KeyExchangeBOriginalInfoDef infoB =
    { {0},{0},privKeyB[0],privKeyB[1],privKeyB[2],privKeyB[3],pubKeyA,pubKeyB,0,1,{0},G };

    for (int i = 0; i < 4; i++)
    {
        infoA.n[i] = ellipticCurve_n[3 - i];
        infoB.n[i] = ellipticCurve_n[3 - i];
    }
    infoA.w = (int)(GetMSB(infoA.n) / 2 + 1) - 1;	//w = [log2(n)/2] - 1	+1是向上取整,大质数取对数必带小数点
    infoB.w = infoA.w;

    tmp[0] = ENTLAInBit >> 8;
    tmp[1] = ENTLAInBit & 0xff;
    memcpy(tmp + 2, IDA, ENTLAInBit / 8);
    Uint256ToString(tmp1, Ec->a);
    memcpy(tmp + 2 + ENTLAInBit / 8, tmp1, 32);
    Uint256ToString(tmp1, Ec->b);
    memcpy(tmp + 2 + ENTLAInBit / 8 + 32, tmp1, 32);
    Uint256ToString(tmp1, G->x);
    memcpy(tmp + 2 + ENTLAInBit / 8 + 32 * 2, tmp1, 32);
    Uint256ToString(tmp1, G->y);
    memcpy(tmp + 2 + ENTLAInBit / 8 + 32 * 3, tmp1, 32);
    Uint256ToString(tmp1, pubKeyA->x);
    memcpy(tmp + 2 + ENTLAInBit / 8 + 32 * 4, tmp1, 32);
    Uint256ToString(tmp1, pubKeyA->y);
    memcpy(tmp + 2 + ENTLAInBit / 8 + 32 * 5, tmp1, 32);
    SM3(tmp, 2 + ENTLAInBit / 8 + 32 * 6, infoA.ZA);
    memcpy(infoB.ZA, infoA.ZA, 32);

    tmp[0] = ENTLBInBit >> 8;
    tmp[1] = ENTLBInBit & 0xff;
    memcpy(tmp + 2, IDB, ENTLBInBit / 8);
    Uint256ToString(tmp1, Ec->a);
    memcpy(tmp + 2 + ENTLBInBit / 8, tmp1, 32);
    Uint256ToString(tmp1, Ec->b);
    memcpy(tmp + 2 + ENTLBInBit / 8 + 32, tmp1, 32);
    Uint256ToString(tmp1, G->x);
    memcpy(tmp + 2 + ENTLBInBit / 8 + 32 * 2, tmp1, 32);
    Uint256ToString(tmp1, G->y);
    memcpy(tmp + 2 + ENTLBInBit / 8 + 32 * 3, tmp1, 32);
    Uint256ToString(tmp1, pubKeyB->x);
    memcpy(tmp + 2 + ENTLBInBit / 8 + 32 * 4, tmp1, 32);
    Uint256ToString(tmp1, pubKeyB->y);
    memcpy(tmp + 2 + ENTLBInBit / 8 + 32 * 5, tmp1, 32);
    SM3(tmp, 2 + ENTLBInBit / 8 + 32 * 6, infoB.ZB);
    memcpy(infoA.ZB, infoB.ZB, 32);
    free(tmp);
    free(tmp1);

    uint256_t rA = { 0 };
    SM2KeyExchange_AStep1To3(RA, rA, infoA);	//A step1~3,generate RA

    SM2KeyExchange_BStep1To4(tB, RB, infoB);	//B step1~4
    if (!IsValidPoint(RA, Ec))	//B 判断RA是否满足曲线方程
    {
        return FALSE;
    }
    SM2KeyExchange_BStep5To6(V, tB, RA, infoB);	//B step5~6
    if (IsZeroPoint(V))	//B 判断V是否为(0,0)
    {
        return FALSE;
    }

    uint8_t* SB = malloc(32), * KB = malloc(klenInBit / 8);
    SM2KeyExchange_BStep7To9(KB, SB, *V, klenInBit, *RA, *RB, infoB);	//B step7~9

    uint256_t tA = { 0 };
    SM2KeyExchange_AStep4To5(tA, RA, rA, infoA);	//A step4~5

    if (IsZeroPoint(RB))	//A 判断RB是否为(0,0)
    {
        return FALSE;
    }

    SM2KeyExchange_AStep6To7(U, tA, RB, infoA);	//A step6~7
    if (IsZeroPoint(U))	//A 判断U是否为(0,0)
    {
        return FALSE;
    }
    uint8_t* S1 = malloc(32), * KA = malloc(klenInBit / 8);
    SM2KeyExchange_AStep8To9(KA, S1, *U, klenInBit, *RA, *RB, infoA);	//A step8~9

    if (KeyExchangeCheck)
    {
        for (int i = 0; i < 32; i++)//A 判断S1是否==SB
        {
            if (S1[i] != SB[i])
            {
                return FALSE;
            }
        }
    }

    uint8_t* SA = malloc(32);
    SM2KeyExchange_AStep10(SA, *U, *RA, *RB, infoA);	//A step10

    uint8_t* S2 = malloc(32);
    SM2KeyExchange_BStep10(S2, *V, *RA, *RB, infoB);	//B step10

    if (KeyExchangeCheck)
    {
        for (int i = 0; i < 32; i++)//B 判断S2是否==SA
        {
            if (S2[i] != SA[i])
            {
                return FALSE;
            }
        }
    }
    free(RA);
    free(V);
    free(U);
    free(pubKeyA);
    free(pubKeyB);
    free(RB);
    free(SB);
    free(KB);
    free(S1);
    free(KA);
    free(SA);
    free(S2);

    return TRUE;
}

/**
  * @name    SM2KeyExchange_AStep1To3
  * @brief   用户A:step1~3
  * @param   RA
  * @param   rA
  * @param   infoA
  * @retval  RA
  * @retval  rA
  * @author  FZM
  * @date    2022-05-09 20:32:10
  */
void SM2KeyExchange_AStep1To3(EccPoint* RA, uint64_t* rA, KeyExchangeAOriginalInfoDef infoA)
{
    GetRandomNumber(rA, Ec->p);
#ifdef DEBUG_MODE
    for (int i = 0; i < 4; i++)	//测试固定随机数
    {
        rA[i] = exRandom_rA[3 - i];
    }
#endif
    CurvePointMul(RA, infoA.G, rA);
}

/**
  * @name    SM2KeyExchange_AStep4To5
  * @brief   用户A:step4~5
  * @param   tA
  * @param   RA
  * @param   rA
  * @param   infoA
  * @retval  tA
  * @author  FZM
  * @date    2022-05-10 09:26:20
  */
void SM2KeyExchange_AStep4To5(uint64_t* tA, EccPoint* RA, uint64_t* rA, KeyExchangeAOriginalInfoDef infoA)
{
    uint256_t x1_ = { 0 };

    Uint256Cpy(x1_, RA->x);
    Uint256WriteBits(x1_, 0, infoA.w + 1, 255);
    Uint256WriteBits(x1_, 1, infoA.w, infoA.w);	//step4:x1_ = 2^w + (x1 & (2^w - 1))就是把bit w置1，前面的置0
    vli_modMult(tA, x1_, rA, infoA.n);
    vli_modAdd(tA, tA, infoA.dA, infoA.n);	//step5:tA = (dA + x1_ * rA)modn
}

/**
  * @name    SM2KeyExchange_AStep6To7
  * @brief   用户A:step6~7
  * @param   resultU
  * @param   tA
  * @param   RB
  * @param   infoA
  * @retval  resultU
  * @author  FZM
  * @date    2022-05-10 09:39:55
  */
void SM2KeyExchange_AStep6To7(EccPoint* resultU, uint64_t* tA, EccPoint* RB, KeyExchangeAOriginalInfoDef infoA)
{
    uint256_t x2_ = { 0 };
    EccPoint* tmp = malloc(sizeof(EccPoint));

    memset(resultU, 0, 32);
    Uint256Cpy(x2_, RB->x);
    Uint256WriteBits(x2_, 0, infoA.w + 1, 255);
    Uint256WriteBits(x2_, 1, infoA.w, infoA.w);	//step6:x2_ = 2^w + (x2 & (2^w - 1))就是把bit w置1，前面的置0
    CurvePointMul(resultU, RB, x2_);
    CurvePointAdd(tmp, resultU, infoA.PB);
    CurvePointMul(resultU, tmp, tA);	//step7: U = [h*tA](PB+[x2_]*RB)这里的h我不会算
    free(tmp);
}

/**
  * @name    SM2KeyExchange_AStep8To9
  * @brief   用户A:step8~9
  * @param   KA
  * @param   S1
  * @param   U
  * @param   klenInBit
  * @param   RA
  * @param   RB
  * @param   infoA
  * @retval	 KA
  * @retval	 S1
  * @author  FZM
  * @date    2022-05-10 09:47:51
  */
void SM2KeyExchange_AStep8To9(uint8_t* KA, uint8_t* S1, EccPoint U, int klenInBit, EccPoint RA, EccPoint RB, KeyExchangeAOriginalInfoDef infoA)
{
    uint8_t* tmp = malloc(32 + 32 + 32 + 32), * tmp1 = malloc(32);	//tmp = xV||yV||ZA||ZB

    Uint256ToString(tmp1, U.x);
    memcpy(tmp, tmp1, 32);
    Uint256ToString(tmp1, U.y);
    memcpy(tmp + 32, tmp1, 32);
    memcpy(tmp + 64, infoA.ZA, 32);
    memcpy(tmp + 96, infoA.ZB, 32);
    KDF(KA, tmp, (32 + 32 + 32 + 32) * 8, klenInBit);	//step7: 生成秘钥KB = KDF(xV||yV||ZA||ZB,klenInBit)
    if (KeyExchangeCheck)//需要校验S1==SB
    {
        tmp = realloc(tmp, 32 * 7);
        Uint256ToString(tmp1, U.x);
        memcpy(tmp, tmp1, 32);
        memcpy(tmp + 32, infoA.ZA, 32);
        memcpy(tmp + 64, infoA.ZB, 32);
        Uint256ToString(tmp1, RA.x);
        memcpy(tmp + 96, tmp1, 32);
        Uint256ToString(tmp1, RA.y);
        memcpy(tmp + 128, tmp1, 32);
        Uint256ToString(tmp1, RB.x);
        memcpy(tmp + 160, tmp1, 32);
        Uint256ToString(tmp1, RB.y);
        memcpy(tmp + 192, tmp1, 32);
        SM3(tmp, 32 * 7, tmp1);	//tmp1 = Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2)

        tmp[0] = 0x02;
        memcpy(tmp + 1 + 32, tmp1, 32);
        Uint256ToString(tmp1, U.y);
        memcpy(tmp + 1, tmp1, 32);
        SM3(tmp, 65, S1);	//S1 =  Hash(0x02 ∥ yV ∥ Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2))
    }
    free(tmp);
    free(tmp1);
}

/**
  * @name    SM2KeyExchange_AStep10
  * @brief   用户A:step10
  * @param   SA
  * @param   U
  * @param   RA
  * @param   RB
  * @param   infoA
  * @retval	 SA
  * @author  FZM
  * @date    2022-05-10 09:48:46
  */
//uint8_t tmp[128], tmp1[32];
void SM2KeyExchange_AStep10(uint8_t* SA, EccPoint U, EccPoint RA, EccPoint RB, KeyExchangeAOriginalInfoDef infoA)
{
    uint8_t* tmp = malloc(32 + 32 + 32 + 32), * tmp1 = malloc(32);	//tmp = xV||yV||ZA||ZB

    if (KeyExchangeCheck)//需要校验S2==SA
    {
        tmp = realloc(tmp, 32 * 7);
        Uint256ToString(tmp1, U.x);
        memcpy(tmp, tmp1, 32);
        memcpy(tmp + 32, infoA.ZA, 32);
        memcpy(tmp + 64, infoA.ZB, 32);
        Uint256ToString(tmp1, RA.x);
        memcpy(tmp + 96, tmp1, 32);
        Uint256ToString(tmp1, RA.y);
        memcpy(tmp + 128, tmp1, 32);
        Uint256ToString(tmp1, RB.x);
        memcpy(tmp + 160, tmp1, 32);
        Uint256ToString(tmp1, RB.y);
        memcpy(tmp + 192, tmp1, 32);
        SM3(tmp, 32 * 7, tmp1);	//tmp1 = Hash(xU ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2)

        tmp[0] = 0x03;
        memcpy(tmp + 1 + 32, tmp1, 32);
        Uint256ToString(tmp1, U.y);
        memcpy(tmp + 1, tmp1, 32);
        SM3(tmp, 65, SA);	//SA = Hash(0x02 ∥ yU ∥ Hash(xU ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2))
    }
    free(tmp);
    free(tmp1);
}

/**
  * @name    SM2KeyExchange_BStep1To4
  * @brief   用户B step1~4
  * @param   tB
  * @param   RB
  * @param   infoB
  * @retval	 tB
  * @retval	 RB
  * @author  FZM
  * @date    2022-05-10 09:49:04
  */
void SM2KeyExchange_BStep1To4(uint64_t* tB, EccPoint* RB, KeyExchangeBOriginalInfoDef infoB)
{
    uint256_t rB = { 0 }, x2_ = { 0 };

    memset(tB, 0, 32);
    GetRandomNumber(rB, Ec->p);	//step1 generate rB
#ifdef DEBUG_MODE
    for (int i = 0; i < 4; i++)	//测试固定随机数
    {
        rB[i] = exRandom_rB[3 - i];
    }
#endif
    CurvePointMul(RB, G, rB);	//step2:RB = rB*G = (x2,y2)

    Uint256Cpy(x2_, RB->x);
    Uint256WriteBits(x2_, 0, infoB.w + 1, 255);
    Uint256WriteBits(x2_, 1, infoB.w, infoB.w);	//step3:x2_ = 2^w + (x2 & (2^w - 1))就是把bit w置1，前面的置0
    vli_modMult(tB, x2_, rB, infoB.n);
    vli_modAdd(tB, tB, infoB.dB, infoB.n);	//step4:tB = (dB + x2_*rB)modn
}

/**
  * @name    SM2KeyExchange_BStep5To6
  * @brief   用户B step5~6
  * @param   resultV
  * @param   tB
  * @param   RA
  * @param   infoB
  * @retval	 resultV
  * @author  FZM
  * @date    2022-05-10 09:51:52
  */
void SM2KeyExchange_BStep5To6(EccPoint* resultV, uint64_t* tB, EccPoint* RA, KeyExchangeBOriginalInfoDef infoB)
{
    uint256_t x1_ = { 0 };

    memset(resultV, 0, 32);
    Uint256Cpy(x1_, RA->x);
    Uint256WriteBits(x1_, 0, infoB.w + 1, 255);
    Uint256WriteBits(x1_, 1, infoB.w, infoB.w);	//step5:x1_ = 2^w + (x1 & (2^w - 1))就是把bit w置1，前面的置0
    CurvePointMul(resultV, RA, x1_);
    CurvePointAdd(resultV, resultV, infoB.PA);
    CurvePointMul(resultV, resultV, tB);	//step6: V = [h*tB](PA+[x2_]*RA)
}

/**
  * @name    SM2KeyExchange_BStep7To9
  * @brief   用户B step7~9
  * @param   KB
  * @param   SB
  * @param   V
  * @param   klenInBit
  * @param   RA
  * @param   RB
  * @param   infoB
  * @retval	 KB
  * @retval	 SB
  * @author  FZM
  * @date    2022-05-10 09:53:10
  */
//uint8_t k[128], tmp1[32];
//uint8_t* tmp = k;
void SM2KeyExchange_BStep7To9(uint8_t* KB, uint8_t* SB, EccPoint V, int klenInBit, EccPoint RA, EccPoint RB, KeyExchangeBOriginalInfoDef infoB)
{
    uint8_t* tmp = malloc(32 + 32 + 32 + 32), * tmp1 = malloc(32);	//tmp = xV||yV||ZA||ZB

    Uint256ToString(tmp1, V.x);
    memcpy(tmp, tmp1, 32);
    Uint256ToString(tmp1, V.y);
    memcpy(tmp + 32, tmp1, 32);
    memcpy(tmp + 64, infoB.ZA, 32);
    memcpy(tmp + 96, infoB.ZB, 32);
    KDF(KB, tmp, (32 + 32 + 32 + 32) * 8, klenInBit);	//step7: 生成秘钥KB = KDF(xV||yV||ZA||ZB,klenInBit)
    if (KeyExchangeCheck)//需要校验S2==SA
    {
        tmp = realloc(tmp, 32 * 7);
        Uint256ToString(tmp1, V.x);
        memcpy(tmp, tmp1, 32);
        memcpy(tmp + 32, infoB.ZA, 32);
        memcpy(tmp + 64, infoB.ZB, 32);
        Uint256ToString(tmp1, RA.x);
        memcpy(tmp + 96, tmp1, 32);
        Uint256ToString(tmp1, RA.y);
        memcpy(tmp + 128, tmp1, 32);
        Uint256ToString(tmp1, RB.x);
        memcpy(tmp + 160, tmp1, 32);
        Uint256ToString(tmp1, RB.y);
        memcpy(tmp + 192, tmp1, 32);
        SM3(tmp, 32 * 7, tmp1);	//tmp1 = Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2)

        tmp[0] = 0x02;
        memcpy(tmp + 1 + 32, tmp1, 32);
        Uint256ToString(tmp1, V.y);
        memcpy(tmp + 1, tmp1, 32);
        SM3(tmp, 65, SB);	// SB = Hash(0x02 ∥ yV ∥ Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2))
    }
    free(tmp);
    free(tmp1);
}

/**
  * @name    SM2KeyExchange_BStep10
  * @brief   用户B step10
  * @param   S2
  * @param   V
  * @param   RA
  * @param   RB
  * @param   infoB
  * @retval	 S2
  * @author  FZM
  * @date    2022-05-10 09:53:50
  */
void SM2KeyExchange_BStep10(uint8_t* S2, EccPoint V, EccPoint RA, EccPoint RB, KeyExchangeBOriginalInfoDef infoB)
{
    uint8_t* tmp = malloc(32 + 32 + 32 + 32), * tmp1 = malloc(32);	//tmp = xV||yV||ZA||ZB

    if (KeyExchangeCheck)//需要校验S2==SA
    {
        tmp = realloc(tmp, 32 * 7);
        Uint256ToString(tmp1, V.x);
        memcpy(tmp, tmp1, 32);
        memcpy(tmp + 32, infoB.ZA, 32);
        memcpy(tmp + 64, infoB.ZB, 32);
        Uint256ToString(tmp1, RA.x);
        memcpy(tmp + 96, tmp1, 32);
        Uint256ToString(tmp1, RA.y);
        memcpy(tmp + 128, tmp1, 32);
        Uint256ToString(tmp1, RB.x);
        memcpy(tmp + 160, tmp1, 32);
        Uint256ToString(tmp1, RB.y);
        memcpy(tmp + 192, tmp1, 32);
        SM3(tmp, 32 * 7, tmp1);	//tmp1 = Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2)

        tmp[0] = 0x03;
        memcpy(tmp + 1 + 32, tmp1, 32);
        Uint256ToString(tmp1, V.y);
        memcpy(tmp + 1, tmp1, 32);
        SM3(tmp, 65, S2);	//tmp1 = SB = SB= Hash(0x02 ∥ yV ∥ Hash(xV ∥ ZA ∥ ZB ∥ x1 ∥ y1 ∥ x2 ∥ y2))
    }
    free(tmp);
    free(tmp1);
}

/**
  * @name    GetMSB
  * @brief   uint256_t 获得最高位的位置
  * @param   num
  * @retval  int
  * @author  FZM
  * @date    2022-05-10 09:55:33
  */
int GetMSB(uint64_t* num)
{
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 63; j >= 0; j--)
        {
            if (num[i] & (1ULL << j))
            {
                return 64 * i + j;
            }
        }
    }
    return 0;
}

/**
  * @name    Uint256WriteBits
  * @brief   uint256_t从startBitPos到stopBitPos写bitnum
  * @param   num
  * @param   bitNum
  * @param   startBitPos
  * @param   stopBitPos
  * @author  FZM
  * @date    2022-05-10 09:54:47
  */
void Uint256WriteBits(uint64_t* num, BOOL bitNum, int startBitPos, int stopBitPos)
{
    for (int i = startBitPos; i <= stopBitPos; i++)
    {
        if (bitNum)
        {
            num[i / 64] |= 1ULL << (i % 64);
        }
        else
        {
            num[i / 64] &= ~(1ULL << (i % 64));
        }
    }
}

