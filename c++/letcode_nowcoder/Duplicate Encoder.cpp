#include <string>
using namespace std;
#include <algorithm>
#include<map>
#include <iostream>
// std::string duplicate_encoder(const std::string& word){
//   int n = word.length();
//   transform(word.begin(),word.end(),word.begin(),::tolower);
//   string s;
//   unordered_map<char,int>mp;
//   for (int i = 0; i < n; ++i) {
//     ++mp[word[i]];
//   }
//   for (int i = 0; i < n; ++i) {
//     if (mp[word[i]] == 1) {
//       s += '(';
//     } else {
//       s += ')';
//     }
//   }
//   return s;
// }
int main()
{
    
    string k = "abc";
    //k += '8';
    cout << k ;
    //cout << duplicate_encoder(k) << endl;
    return 0;

}
