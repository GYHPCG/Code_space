#include <iostream>

using namespace std;

int recursion(int x) {
    if(x < 0) return 0;
    if(x>=0 && x < 2) return 2;
    return 2 * recursion(x - 2) + x + 5;
}

int main()
{
    int x;
    int res = recursion(x);
    cout << res << endl;
    return 0;

}
