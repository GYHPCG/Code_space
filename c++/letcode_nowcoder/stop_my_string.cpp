#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string spinWords(const std::string &str)
{
  vector<string> res;
  int n = str.length();
  for (int i = 0; i < n;) {
      string s = "";
      int j = i;
    while(str[j] != ' ' && j < n) {
        s += str[j];
        ++j;
      
    }
    i = j+1;
    res.push_back(s);
  }
//   for(int i = 0; i < res.size(); ++i) {
//     cout << res[i] << " ";
//   }
  int n1 = res.size();
  string s = "";
  for (int i = 0; i < n1;++i) {
    int n = res[i].length();
    if ( n >= 5) {
      string &k = res[i];
      reverse(k.begin(),k.end());
    }
    if (i == 0) {
      s += res[i];
    }else {
         s += ' ';
         s += res[i];
    }
    
     
    
  }
  
    return s;
}// spinWords
int main()
{
    cout << spinWords("Burgers are my favorite fruit");
    return 0;

}
