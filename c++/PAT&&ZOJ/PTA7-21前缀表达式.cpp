#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
 
using namespace std;
 
double cal(double a, double b, char op){
    if (op == '-') return a-b;
    else if (op == '+') return a+b;
    else if (op == '*') return a*b;
    else if (b == 0){ 
        cout << "ERROR";
        exit(0);
    }
    return a/b;
}
 
int main() {
    string str;
    double a, b;
    vector<string> v;
    stack<double> s;
    
    while (cin >> str) // 读入表达式
        v.push_back(str);
    for (int i = v.size()-1; i >= 0; i--){
        str = move(v[i]);
        if (isdigit(str[str.length()-1])) // 数字入栈
            s.push(stod(str));
        else { // 计算
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(cal(a, b, str[0]));
        }
    }
    printf("%.1lf", s.top());
    
    return 0;
}

