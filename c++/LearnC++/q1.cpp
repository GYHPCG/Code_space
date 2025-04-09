/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-08 21:46:55
 * @LastEditors: CGPan
 * @LastEditTime: 2023-03-14 21:46:33
 */
#include <iostream>

using namespace std;
class abc{
    public:
    static int x;
    int i;

    abc(){
        i = ++x;
    }
};
int abc::x;
int main()
{
    //abc m,n,p;
    //cout << m.x << " " << m.i << endl;
    cout << 1 % 8 << endl;
   
    int 变量 = 1;
    cout << 变量 << endl;
    string k;
    cin >> k;
    cout << k;
     return 0;
}

