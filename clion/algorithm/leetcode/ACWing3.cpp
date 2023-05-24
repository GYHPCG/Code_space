//
// Created by 86183 on 2023/3/22.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int P = 1e+9 + 7;
using ll = long long;
ll get(int a, int b)
{

   ll res = 1;
   int at = a;
   while (a >= at - b + 1)
   {
      res =(ll) res * a;
      --a;
   }
   ll t = 1;

   while( b >= 2)
   {
      t =(ll) t * b;
      --b;
   }
   cout << "res: " << res << endl;
   cout << "t: " << t << endl;
   return res / t;

}
vector<string> cards = {"S1", "S2", "S3",
                        "S4", 'S5', 'S6',
                        'S7', 'S8', 'S9',
                        'S10', 'S11', 'S12',
                        'S13',
                        'H1', 'H2', 'H3',
                        'H4', 'H5', 'H6',
                        'H7', 'H8', 'H9',
                        'H10', 'H11', 'H2',
                        'H13',
                        'C1', 'C2', 'C3',
                        'C4', 'C5', 'C6',
                        'C7', 'C8', 'C9',
                        'C10', 'C1', 'C12',
                        'C13',
                        'D1', 'D2', 'D3',
                        'D4', 'D5', 'D6',
                        'D7', 'D8', 'D9',
                        'D10', 'D11', 'D12',
                        'D13',
                        'J1', 'J2'
};


int main()
{
   int n;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n;
   int a, b;
   while (n -- )
   {
      cin >> a >> b;

      cout << get(a, b) << endl;
   }



   return 0;
}