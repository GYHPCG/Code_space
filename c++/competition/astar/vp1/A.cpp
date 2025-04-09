#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int x[N],y[N];
int num;
int main(){
   
   cin >> num;
   for (int i = 0; i < num; i++) {
       int n, m;
       cin >> n >> m;
       for (int j = 0; j < n; j++) {
           cin >> x[j] >> y[j];
       }
       int min_ca = INT_MAX;

        for (int i = 0; i < n; ++i) {
            // 计算至少需要喝多少瓶第 i 种饮料 向上取整
            int bottles_needed = (m + x[i] - 1) / x[i];
            int total_ca = bottles_needed * y[i];
            if (total_ca < min_ca) {
                min_ca = total_ca;
            }
        }
      cout << min_ca << endl;
   }
   return 0;
}
