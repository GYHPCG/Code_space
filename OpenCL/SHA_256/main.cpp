#include "sha256.h"


void crypt_and_print(char* input)
{
  char result[65];
  sha256_crypt(input,result);
  printf("'%s':\n%s\n", input, result);
}

int main()
{
  //SHA-256���ܵĽ����ϢժҪΪ32�ֽ�256bit,�������Ϊ65���㹻�Ž��
	char result[65];
	//��SHA256���г�ʼ����������2048��kpc
	sha256_init(2048);
	//�����1��sha256���ܺ����ϢժҪ��6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b
	crypt_and_print((char*)"1");
	//���"12"sha256���ܺ����ϢժҪ:6b51d431df5d7f141cbececcf79edf3dd861c3b4069f0b11661a3eefacbba918
	crypt_and_print((char*)"12");
	//���"123"sha256���ܺ����ϢժҪ:a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3
	crypt_and_print((char*)"123");
	//���"123"sha256���ܺ����ϢժҪ:4d27a733bfffd740e782bdeb0e617de620e6836826b77445dbbdeda610292bdf
	crypt_and_print((char*)"1234567890123456789012345678901234567890123456789012345678901234567890");
}
