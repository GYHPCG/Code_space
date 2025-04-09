 #include<stdio.h>
int func(int x,int y)
{
	int q; 
    if(x > 9)
    {
        q = 13;
        y = x * y;
        if( x <= 19)
        {
            q = y;
        }
    }
    else
    {
         q = x + y;
        int t = x;
        t = t - y;
        if(x >= y)
        {
            q  = t;
        }
    }
    return q;
}
void main()
{
   int x,y;
   scanf("%d%d",&x,&y);
   printf("%d\n",func(x,y));
    return ;
}

