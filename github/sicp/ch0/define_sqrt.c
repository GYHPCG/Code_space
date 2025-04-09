#include <stdio.h>
#include <math.h>
// #define sq(x) (
//     while ()    
// )
double sq(int x)
{
    double t = 1, tmp = 1;
    while (abs(tmp - t) >= 1e-5)
    {
        tmp = t;
        t = (t + x / t);
    }
    return t;
    
}

int main()
{
    int res = sq(5);
    printf("%d\n ",res);
    return 0;
}