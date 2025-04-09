#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
int square_digits(int num) {
  std::string s = std::to_string(num);
  cout << s << endl;
  int k = 0;
  //string sk = "";
  auto n =  s.length();
  for (int i = 0; i <(int) n; ++i) {
    int b = s[i] -'0';
    b = pow(b,2);
    if ( b > 9) {
      k = k * 100 + b;
    }
    else k = k * 10 + b;
  }
  //cout << sk << endl;
 return k;
}
int main() {
    int x = 13579;
    cout << square_digits(x) << endl;
    string k = "123";
    string w = "456";
    k += w;
    return 0;
}