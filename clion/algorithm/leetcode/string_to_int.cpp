//
// Created by 86183 on 2023/3/11.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
   int strToInt(string str) {
      //cout << !isdigit(str[0]) << endl;
      //cout << (str[0] != '-') << endl;
      if (!isdigit(str[0]) && (str[0] != '-') && (str[0] != '+') && str[0] != ' ') return 0;
      //out << "hh" << endl;
      string t{};
      bool f = false;
      int k = 0;
      while (str[k] == ' ') k++;
      for (int i = k; i < str.length(); ++i)
      {
         if (str[k] == '-') {
            f = true;
            continue;
         }
         if (str[k] == '+') continue;
         if (!isdigit(str[i])) break;

         t += str[i];

      }
      cout << t << endl;
      //return f? -stoi(t):stoi(t);
      return 1;

   }
};
int main()
{
   string s = "    -42"s;

   Solution s1;
   cout << s1.strToInt(s);

   return 0;
}
