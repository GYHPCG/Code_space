#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {9 ,4, 67 ,3 ,4, 1};
    sort(a, a + 6);
    for (int i = 0; i < 6; ++i)
    cout << a[i] << ' ';

}