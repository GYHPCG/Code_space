#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rectangleArea(int n) {
     int sum = 1;
    for (int i = 1; i < n; ++i) {
      sum += 2 * i;
    }
  return sum;
}
int main()
{
    
    cout << rectangleArea(3) << endl;
    return 0;

}
