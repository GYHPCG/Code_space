#include <stdio.h>

void sub (int *a, int n, int k)

{  if (k<=n) sub(a,n/2,2*k);

      *a+=k;

}

void main ()

{  int  x=0;

     sub (&x,8,1);

     printf ("x=%d\n",x);
 }
