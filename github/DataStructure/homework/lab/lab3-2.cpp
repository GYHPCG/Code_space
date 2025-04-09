/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-26 10:19:14
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-26 11:24:44
 */
#include <iostream>
#include <string>
using namespace std;

const int Maxsize = 100;
struct Stack {
    char * Data;   // 栈空间
    int Top;      // 栈顶，为0时表示空栈
    int MaxSize; //栈的最大容量
};
Stack* creatStack() {
    Stack* st = new Stack();
    st->MaxSize = Maxsize;
    st->Data = new char[st->MaxSize];
    st->Top = 0;
    return st;
}
void Push(Stack* st, char x) {
    if (st->Top == st->MaxSize) throw runtime_error(" Stack is full");
    st->Data[++st->Top] = x;
}
char Pop(Stack* st) {
    if (st->Top == 0) throw runtime_error("Stack is empty");
    int tem = st->Data[st->Top];
    st->Top--;
    return tem;
}
void PrintStack(Stack* st) {
    while(st->Top != 0) {
        cout << Pop(st) << " ";
    }
    cout << endl;
}
//判断是否{}、[]、()三种括号;
bool judgeSymbol(char k) {
    if (k == '{' || k == '[' || k == '(' || k == '}' || k == ']' || k == ')') 
        return true;
    return false;
}
bool TestStack(Stack* st, string& s) {
    int n  = s.size();
    for (int i = 0; i < n; ++i) {
        //是{}、[]、()三种括号;
        if (judgeSymbol(s[i])) {
            //第一种情况：匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了，比左括号先入栈代码实现要简单
            if (s[i] == '{') Push(st,'}');
            else if (s[i] == '[') Push(st,']');
            else if (s[i] == '(') Push(st,')');
            //第二种：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第三种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st->Top == 0 || st->Data[st->Top] != s[i]) return false;
            else Pop(st);
        }
    }
    return st->Top == 0;
}
void deleteStack(Stack* st) {
    delete[] st->Data;
}
int main()
{
    string s;
    cout << "输入字符串：" << endl;
    cin >> s;
    Stack* st = creatStack();
    bool result = TestStack(st,s);
    cout << "输出结果：" << endl;
    cout << result << endl;
    deleteStack(st);
    return 0;
}