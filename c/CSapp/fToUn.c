#include<stdio.h>
unsigned fToUn(float f) {
	union {
		 float f;
		  unsigned u;
	}t;
	t.f = f ;
	return t.u;
}
int main()
{
	float f;
//	scanf("%f",&f);
//	printf("%d\n",fToUn(f));
//	float s = 1.0/0.0;
//	printf("%f\n",s);
	unsigned int n = 1;
	f = (float)n;
	printf("%f\n",f);
	return 0;
}
