/**
  ******************************************************************************
  * @FileName   : main.c
  * @Version    : 
  * @Author     : 付泽铭 https://blog.csdn.net/XiaoMing_
  * @Date       : 2022-05-12
  * @Brief      : Fp域上的SM2加密、数字签名以及秘钥交换算法主流程
  ******************************************************************************
  */
#include <stdio.h>
#include <string.h>
#include "SM2.h"
#include "SM3.h"
#include "ECC.h"

#ifdef USE_ON_STM32
#include "delay.h"
#include "usart.h"
#endif

#pragma warning(disable:4996)

extern EllipticCurveDef Ec[1];
//EccPoint* G;
EccPoint G[1];
uint8_t C[505];//存放resC

#define TEST_ENCRYPT
#define TEST_SIGN
#define TEST_EXCHANGE

int main()
{
    while (1) {
        uint64_t privKey[4];
        //uint64_t* privKey = (uint64_t*)malloc(sizeof(uint64_t) * 4);
        EccPoint pubKey[1];
        //EccPoint* pubKey = (EccPoint*)malloc(sizeof(EccPoint));
        char* testMessage = "The Little Prince is a novella by French aristocrat, writer.\n\
It was first published in English and French in the US by Reynal & Hitchcock in April 1943.\
\nThe story follows a young prince who visits various planets in space, including Earth, and addresses themes of loneliness, friendship, love, \
and loss.Despite its style as a children's book, The Little Prince makes observations about life and human nature.";
        int lenTestMessage = strlen(testMessage);

#ifdef USE_ON_STM32
        uart_init(115200);
        //	delay_init();
        printf("STM32 SM2 testing...\n");
#endif
        //G = malloc(sizeof(EccPoint));
        //G[1];
        for (int i = 0; i < 4; i++)
        {
            G->x[i] = ellipticCurve_Gx[3 - i];
            G->y[i] = ellipticCurve_Gy[3 - i];
        }

        EllipticCurveInit(ellipticCurve_a, ellipticCurve_b, ellipticCurve_p);
        if (!IsValidPoint(G, Ec))
        {
            while (1);
        }

    GenerateKey:
        if (!GenerateKeys(privKey, pubKey, G))
        {
            while (1);
        }
        if (!IsValidPoint(pubKey, Ec))
        {
            goto GenerateKey;
        }
#ifdef TEST_ENCRYPT
        uint8_t* resC = SM2Encrypt(testMessage, lenTestMessage * 8, pubKey);
        uint8_t* resSM2Decrypt = SM2Decrypt((char*)resC, 65 + 32 + lenTestMessage * 8 / 8, privKey);
        printf("Decryption %s\n", strcmp(testMessage, resSM2Decrypt) ? "failed" : "passed");
        //free(resC);
        free(resSM2Decrypt);
#endif  //TEST_ENCRYPT

#ifdef TEST_SIGN
        char* IDA = "ALICE123@YAHOO.COM";
        char* m = "message digest";
        SM2Signature* sign = SM2Sign(m, 8 * strlen(m), IDA, 0x0090, G, pubKey, privKey);
        int v = SM2SignatureVerify(m, 8 * strlen(m), sign, IDA, 0x0090, G, pubKey);
        printf("Signature verification %s \n", v ? "passed" : "failed");
        free(sign);
#endif // TEST_SIGN

#ifdef TEST_EXCHANGE
        char* IDA2 = "ALICE123@YAHOO.COM";
        char* IDB2 = "BILL456@YAHOO.COM";
        int resSM2KeyExchange = SM2KeyExchange(IDA2, 0x0090, IDB2, 0x0088, G, 128);
        printf("Key exchange %s\n", resSM2KeyExchange ? "passed" : "failed");
#endif	//TEST_EXCHANGE

        //free(pubKey);
        //free(privKey);
        //free(Ec);
        //free(G);
        break;
    }
}
