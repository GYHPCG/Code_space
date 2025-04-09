#include<stdio.h>

void showIP(int x)
{
	unsigned int a=0,b=0,c=0,d=0;
	 for(int i =0;i<8;i++)
	 {
	 	if((x>>i)&1)d+=(1<<i);
	 }
	 for(int i=8;i<16;i++)
	 {
		 if((x>>i)&1)c+=(1<<i);
	 }
	 c=(c>>8);
	 for(int i=16;i<24;i++)
	 {
	 	if((x>>i)&1)b+=(1<<i);
	  }
	  b=(b>>16);
	  for(int i=24;i<32;i++)
	  {
	  	if((x>>i)&1)a+=(1<<i);
	  }
	  a=(a>>24);
	  printf("%d.%d.%d.%d\n",a,b,c,d); 
	
}
int main()
{

    int x;

    scanf("%d",&x);

    showIP(x);

    return 0;



} 
