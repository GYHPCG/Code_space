/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2023-01-04 09:56:02
 * @LastEditors: CGPan
 * @LastEditTime: 2023-01-04 10:48:39
 */
#include <iostream>
using namespace std;

class A {

    public:
    void swim() {
        cout << "A's swim" << endl;
    }
    void swim(bool t) {
        cout << "A's true" << endl;
    }
    void eat() {
        cout << "A's eat" << endl;
    }
};
class B: public A {

    public:
    using A::swim;
    void swim() {
        //A::swim();
        cout << "B's swim" << endl;
    }
  
};
constexpr double GetPi() {return 22.0 / 7; }
constexpr double TwiPi() {return 2 * GetPi();}
int main()
{
     B b;
    // b.swim();
    // A a;
    // a.swim();
    // b.A::swim();//在派生类中调用基类被覆盖的方法
    //A::swim();
    b.swim(true);
    b.swim();
    //b.eat();
    cout << sizeof(long) << endl;
    cout << sizeof(long long ) << endl;

    cout << "constexpr's test" << endl;
   

    cout << GetPi() << endl;
    cout << TwiPi() << endl;
    return 0;
}