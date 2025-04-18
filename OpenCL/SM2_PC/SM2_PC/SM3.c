/**
  ******************************************************************************
  * @FileName   : SM2.c
  * @Version    : v1.0
  * @Author     : 网上抄的
  * @Date       : 2022-05-08
  * @Brief      : SM2加密
  *
  ******************************************************************************
  */

#include "SM3.h"
#include <stdio.h>                                                                                                                                                          
#include <string.h>

static void lk_sm3_cf(lk_sm3_context_t* context)
{
    LK_MSG_CF(context)
}

void lk_sm3_update(lk_sm3_context_t* context, UCHAR* data, UINT len)
{
    int real_len, free, offset = 0;

    real_len = len + context->len;
    if (real_len < LK_GVALUE_LEN) {
        //本次数据不够一个分组大小,先缓存起来
        memcpy(context->data + context->len, data + offset, len);
        context->len = real_len;
        context->total += len;
        return;
    }
    free = LK_GVALUE_LEN - context->len;
    memcpy(context->data + context->len, data + offset, free);
    context->total += free;
    offset += free;
    len -= free;
    //进行迭代压缩
    lk_sm3_cf(context);

    while (1) {
        if (len < LK_GVALUE_LEN) {
            //本次数据不够一个分组大小,先缓存起来
            memcpy(context->data + context->len, data + offset, len);
            context->len = len;
            context->total += len;
            return;
        }
        memcpy(context->data + context->len, data + offset, LK_GVALUE_LEN);
        offset += LK_GVALUE_LEN;
        len -= LK_GVALUE_LEN;
        context->total += LK_GVALUE_LEN;
        //进行迭代压缩
        lk_sm3_cf(context);
    }
}

void lk_sm3_final(lk_sm3_context_t* context)
{
    UINT tk, k, free, i, len;
    UCHAR tmp[LK_GVALUE_LEN] = { 0 };

    tk = context->total * 8 % 512;
    if (tk < 448) {
        k = 448 - tk;
    }
    else {
        k = 448 - tk + 512;
    }
    //计算需要填充的字节
    k = k / 8 + 8;
    free = LK_GVALUE_LEN - context->len;
    k--;
    context->data[context->len] = 0x80;
    len = context->total * 8;
    for (i = context->len + 1; i < LK_GVALUE_LEN; i++, k--) 
    {
        if (k != 8)
            context->data[i] = 0x00;
        else 
        {
            memset(context->data + i, 0, 8);
            UWORD* pdata = (UWORD*)(4 + &(context->data[i]));
            *pdata = LK_GE_ONE(len);
            break;
        }
    }
    //进行迭代压缩
    lk_sm3_cf(context);
    if (64 == k) {
        for (i = 0; i < LK_GVALUE_LEN; i++, k--) {
            if (k != 8)
                context->data[i] = 0x00;
            else {
                memset(context->data + i, 0, 8);
                UWORD* pdata = (UWORD*)(4 + &(context->data[i]));
                *pdata = LK_GE_ONE(len);
                break;
            }
        }
        //进行迭代压缩
        lk_sm3_cf(context);
    }
    //get result
    LK_LE_ONE(context)
}

void SM3(char* cdata, int sizeInByte, char* res)
{
    lk_sm3_context_t context;
    LK_INIT_VALUE(&context);
    char buffer[1024] = { 0 };

    lk_sm3_update(&context, cdata, sizeInByte);
    lk_sm3_final(&context);
    for (int i = 0; i < 32; i++)
        res[i] = context.output[i];
}