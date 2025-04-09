#include<stdio.h>
#include<math.h> 
int main()
{
	int search(int n);
	int number;
	100<number&&number<1000;
	scanf("%d",&number);
	printf("count=%d\n",search(number));
	return 0;
} 
int search(int n)
{
	int i,j;
	int count=0;
	for(j=101;j<=n;j++){
	    for(i=11;i<35;i++)
    {
		if(i*i==j)
		{
		int a,b,c;
	    a=j%10;
	    b=j/10%10;
	    c=j/100;
		if((a==b)||(b==c)||(a==c))
		{
		
		   count++;
		  continue;
		}
	}

}
}
	return count;

}
