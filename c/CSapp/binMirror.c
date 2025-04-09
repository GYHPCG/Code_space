#include<stdio.h>
int binMirror(int x)
{
	int result = 0;
	for(int i= 0,j=31;i<32;i++,j--)
	{
		if(i!=31)
		{   
		    if((x>>i)&1)
			result += (1<<j);
			else continue;
		}
		else
		{
			if((x>>31)&1)
			result -= 1;
			else continue;
		}
		
	}
	return result;
}
int main(){

    int x;

    scanf("%d",&x);

    printf("%d\n",binMirror(x));

    return 0;

} 
