#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;

bool con_rock;
bool win_cnt;
int n, a, b;
string op;

int get_rock(int k) {
    return a + b * k;
}

int main()
{
    cin >> n >> a >> b;
    cin >> op;
    int sum = 0;
    int k = 0;
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == 'x') {
            sum += get_rock(k); 
            k = 0; 
        } else {
            sum += get_rock(k);
            k++;   
        }
    }
    cout << sum << endl;

    return 0;
}
