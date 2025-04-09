#include<iostream>
#include <string>
using namespace std; 
bool isRoate(int i,char test[]) {
    string s = to_string(i);
    cout << " s: " << s << endl;
    int n = s.size();
    string k = "";
    if( n == 1 && ((test[s[0] - '0'] == '0') || test[s[0] - '0'] == (i + '0'))) return false;
    if (n == 1 && (test[s[0]-'0'] != '0' || test[s[0]-'0']) != (i + '0')) return true;
    for (int j = 0; j < n; ++j) {
        if (test[s[j]-'0'] == '0' && (s[j] - '0')!= 0 ) return false;
        else
        k += test[s[j] - '0'];
    }
    cout << "k : " << k << endl;
    //int num = stoi(k);
    //if (num != i) return true;
    return false;

}
int rotatedDigits(int n) {
    char test[10] = {'0','1','5','0','0','2','9','0','8','6'};
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (isRoate(i,test)) {
            ++sum;
        }
    }
    return sum;
}
int main()
{
	
	int n = 0;
	cin >> n;
	cout << rotatedDigits(n) << endl;
	return 0;
}
