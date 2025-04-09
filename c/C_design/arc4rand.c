/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-22 17:10:23
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-22 19:44:09
 */
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>
 
int main() {
    //int a = 0;
    char inx[16];
    HCRYPTPROV Rnd;
    LPCSTR UserName = "MyKeyContainer";
    if(CryptAcquireContext(&Rnd, UserName, NULL, PROV_RSA_FULL, 0)) {
        printf("A cryptographic context with the %s key container ",
        UserName);
        printf("has been acquired.\n\n");
    } else {
        if (GetLastError() == NTE_BAD_KEYSET) {
            if(CryptAcquireContext(
                &Rnd,
                UserName,
                NULL,
                PROV_RSA_FULL,
                CRYPT_NEWKEYSET)) {
                printf("A new key container has been created.\n");
            } else {
                printf("Could not create a new key container.\n");
                exit(1);
            }
        } else {
            printf("A cryptographic service handle could not be "
            "acquired.\n");
            exit(1);
        }
    }
 
    if (CryptGenRandom(Rnd, 16, (BYTE*)(inx))) {
        for (int i = 0; i < 16; ++i) {
            printf("%d ", inx[i]);
        }
    }
        //printf("%d\n\n", a);
    else
        puts("failed\n");
 
    if (CryptReleaseContext(Rnd,0)) {
      printf("The handle has been released.\n\n");
    } else {
      printf("The handle could not be released.\n\n");
    }
 
    return 0;
}