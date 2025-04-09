#include<stdio.h>
#include<math.h>
int main()
{

    int a=1;
    double p=0.00,i=1.00,b=1.00;
    while(fabs(b)>=1e-6){
        p=p+b;
        a=-a;
        i=i+2;
        b=a/i;
    }
    p=4*p;
    printf("p=%f\n",p);
    return 0;
}
