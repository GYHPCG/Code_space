#include<stdio.h>
#include <iostream>
int divpwr2(int x,int n)
{
	int bv = (1<<n)+~0;
	int br = (x>>31)&bv;
	return (x+br)>>n;
}
int main()
{

    int x,n;

    scanf("%d%d",&x,&n);
    decltype((x)) a = x;
//    std::cout << typeid(a) << std::endl;
    std::cout << typeof(a);
    printf("%d\n",divpwr2(x,n));

    return 0;

} 
