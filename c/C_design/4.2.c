#include<stdio.h>
int main()
{
	int k=4,n=0;
	for(;n<k;){
		n++;
		if(n%3!=0)continue;
		k--;
	}
	printf("%d,%d\n",k,n);
	return 0;
}
