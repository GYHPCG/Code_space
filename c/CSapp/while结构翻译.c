#include<stdio.h>
long func(unsigned long n)
{
    
    long res = 0;
    /*if(n>0)
    {
        int x =1;
        int y =1;
      while(n>=x)
      {
       long x1 = x;
        y = y * x1;
        res = res + y;
        x++;
        
       }
    } */
    while(n)
	{
		res^=n;
		n>>=1;
	 } 
    return res&1;
    
}

void main()
{

     long n;

    scanf("%d",&n);

    long result=func(n);

    printf("%ld\n",result);

    return ;
}

