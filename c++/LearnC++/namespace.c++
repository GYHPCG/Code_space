#include<iostream>
using namespace std;
namespace Numer {
    int add(int a, int b) {
        return a + b + 10;
    }
}
int add(int a, int b) {
    return a + b;
}
namespace N2 {
    int add(int a,int b) {
        return a + b +1;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << add(a , b) <<endl;
    cout << Numer::add(a,b) << endl;
    cout << N2::add(a,b) << endl;
    return 0;

}