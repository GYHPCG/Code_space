#include <iostream>
#include <math.h>
using namespace std;
bool isTriangle(int a, int b, int c)
  {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    int a1 = pow(a,2),b1 = pow(b,2),c1 = pow(c,2);
    if ((a1 + b1 == c1) || (a1 + c1 == b1) || (b1 + c1 == a1)) return true;
    //if (a1 + b1 != c1 && a1 + c1 != b1 && b1 + c1 != a1) return false;
   return false;
  }

int main()
{
    
    cout << isTriangle(15,17,20);
    return 0;

}
