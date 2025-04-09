/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-21 23:55:49
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-22 00:12:24
 */
#include <iostream>

using namespace std;
struct A{
    int x;
    A(int x){
       this->x = x;
    }
    // operator int(){
    //     return x;
    // }
    friend ostream& operator<<(ostream& os, A& b);
};
ostream& operator<<(ostream& os, A& b) {
    os << b.x << endl;
    return os;
}
struct B{
    B(double x);
};

int main()
{
    //void m(const A&);
    //void m(const B&);
    //m(10);
    A s = 3;
    //int i = s + 2;
    //cout << i << endl;
    //A B = s + 8;
    cout << s << endl;
    return 0;

}
