/**
  ******************************************************************************
  * @FileName   : SM2.h
  * @Version    : v1.0
  * @Author     : FZM
  * @Date       : 2022-05-10
  * @Brief      :
  *
  ******************************************************************************
  */

#ifndef __SM2_H
#define __SM2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SM3.h"
#include "ECC.h"

typedef uint64_t uint256_t[4];
typedef int BOOL;

//#define USE_ON_STM32	//打开这个宏定义以加入STM32中的硬件支持（uart，systick）
//#define DEBUG_MODE	//打开这个宏定义以使用固定的随机数

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

typedef struct
{
    uint256_t a;
    uint256_t b;
    uint256_t p;
}EllipticCurveDef;

typedef struct
{
    uint8_t r[32];
    uint8_t s[32];
}SM2Signature;

typedef struct
{
    uint64_t* data;
    uint64_t sizeInLongLong;
}BIG;

typedef struct
{
    uint8_t ZA[32];
    uint8_t ZB[32];
    uint256_t dA;
    EccPoint* PA;
    EccPoint* PB;
    uint32_t w;
    uint32_t h;
    uint256_t n;
    EccPoint* G;
}KeyExchangeAOriginalInfoDef;//秘钥交换中的原始信息

typedef struct
{
    uint8_t ZA[32];//包含IDA的杂凑值
    uint8_t ZB[32];//包含IDB的杂凑值
    uint256_t dB;//私钥B
    EccPoint* PA;//公钥A
    EccPoint* PB;//公钥B
    uint32_t w;
    uint32_t h;
    uint256_t n;	//基点的阶
    EccPoint* G;	//基点
}KeyExchangeBOriginalInfoDef;

extern uint256_t ellipticCurve_a;
extern uint256_t ellipticCurve_b;
extern uint256_t ellipticCurve_p;
extern uint256_t ellipticCurve_n;
extern uint256_t ellipticCurve_Gx;
extern uint256_t ellipticCurve_Gy;
extern uint256_t exPrivateKey;

void EllipticCurveInit(uint64_t* a, uint64_t* b, uint64_t* p);
BOOL IsValidPoint(EccPoint* point, EllipticCurveDef* Ec);
void GetRandomNumber(uint64_t* result, uint64_t* maxVal);
BOOL GenerateKeys(uint64_t* privKey, EccPoint* pubKey, EccPoint* pointG);
void CurvePointAdd(EccPoint* res, EccPoint* p1, EccPoint* p2);
void CurvePointMul(EccPoint* res, EccPoint* p1, uint64_t* times);
void BigNumberCpy(uint64_t* des, uint64_t* src);
void BigBitShift(BIG* num,BOOL shift);
void Uint256ToString(uint8_t* res, uint256_t num);
void StringToUint256(uint64_t* res, uint8_t* num);
void KDF(uint8_t* result, uint8_t* cdata, int datalen, int keylen);
void Uint256WriteBits(uint64_t* num, BOOL bitNum, int startBitPos, int stopBitPos);
int GetMSB(uint64_t* num);

uint8_t* SM2Encrypt(char* messagePlain, int messageSizeInBit, EccPoint* pubKey);
uint8_t* SM2Decrypt(char* C, int lenInByte, uint64_t* privKey);
void CalculateC1(EccPoint* result, uint256_t k, EccPoint* G);
void CalculateKPb(EccPoint* result, uint256_t k, EccPoint* Pb);
void CalculateC2(uint8_t* result, char* M, uint8_t* t, int len);
void CalculateMessage(uint8_t* result, uint8_t* C2, uint8_t* t, int lenInByte);

SM2Signature* SM2Sign(char* message, int messageSizeInBit, char* IDA, uint16_t ENTLAInBit, EccPoint* G, EccPoint* pubKey, uint64_t* privKey);
BOOL SM2SignatureVerify(char* message, int messageSizeInBit, SM2Signature* sign, char* IDA, uint16_t ENTLAInBit, EccPoint* G, EccPoint* pubKey);

BOOL SM2KeyExchange(char* IDA, uint32_t ENTLAInBit, char* IDB, uint32_t ENTLBInBit, EccPoint* G, int klenInBit);
void SM2KeyExchange_AStep1To3(EccPoint* RA, uint64_t* rA, KeyExchangeAOriginalInfoDef infoA);
void SM2KeyExchange_AStep4To5(uint64_t* tA, EccPoint* RA, uint64_t* rA, KeyExchangeAOriginalInfoDef infoA);
void SM2KeyExchange_AStep6To7(EccPoint* resultU, uint64_t* tA, EccPoint* RB, KeyExchangeAOriginalInfoDef infoA);
void SM2KeyExchange_AStep8To9(uint8_t* KA, uint8_t* S1, EccPoint U, int klenInBit, EccPoint RA, EccPoint RB, KeyExchangeAOriginalInfoDef infoA);
void SM2KeyExchange_AStep10(uint8_t* SA, EccPoint U, EccPoint RA, EccPoint RB, KeyExchangeAOriginalInfoDef infoA);
void SM2KeyExchange_BStep1To4(uint64_t* tB, EccPoint* RB, KeyExchangeBOriginalInfoDef infoB);
void SM2KeyExchange_BStep5To6(EccPoint* resultV, uint64_t* tB, EccPoint* RA, KeyExchangeBOriginalInfoDef infoB);
void SM2KeyExchange_BStep7To9(uint8_t* KB, uint8_t* SB, EccPoint V, int klenInBit, EccPoint RA, EccPoint RB, KeyExchangeBOriginalInfoDef infoB);
void SM2KeyExchange_BStep10(uint8_t* S2, EccPoint V, EccPoint RA, EccPoint RB, KeyExchangeBOriginalInfoDef infoB);

#endif	//__SM2_H



