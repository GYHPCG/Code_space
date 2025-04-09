#include<stdio.h>
int func(int a,int b,int c)
{
    int x = c;//x:%r9d
    int y = 0;//y:%r8d
    int res = y;//res:%eax
    if(a>0)
    {
    int z = 10;//z:%r10d
    int t = 1;//t:%r11d;
    int m = 1;//m:%ebx;
    int x1 = m;//x1:%ecx
      if(b>0)
      {  
      	for(t=1;t<=a;t++)
      	{
			
	         for(x1 = m;x1 <= b;x1++)
	         {
				 int y1 = x1 + z;//y1:%edx
	             res = y1;
	             y1 = y1>>31;
	             y1 = res%x;
	             if(y1<1) y ++ ;
	         }
	         z = z+10;
    	}
      }
		
    }
	res = y;
    return res;
    
}

int main()
{
int a,b,c;

scanf("%d%d%d",&a,&b,&c);

printf("%d\n",func(a,b,c));

return 0;

}
/*#include<stdio.h>
#define L long
int func(int a, int b, int c)
{        //%edi    %esi   %edx
    int eb, ea;
    L rc;
    L r9 = c;
    L r8 = 0;
    if(a > 0)
    {
        L r10 = 10;
        L r11 = 1;
        eb = 1;
        do
        {
            rc = eb;
            if(a > 0)
            {
                do
                {
                    c = r10 + rc;
                    ea = c;
                    c >>= 31;
                    c = ea % r9;
                    ea = ea / r9;
                    if(c - 1 < 0) r8 ++;
                    rc ++;
 
                }while(b >= rc);
            }
            r11++;
            r10 += 10;
 
        }while(a >= r11);
    }
    ea = r8;
    return ea;
}
 
int main()
{
 
    int a,b,c;
 
    scanf("%d%d%d",&a,&b,&c);
 
    printf("%d\n",func(a,b,c));
 
    return 0;
 
}*/

