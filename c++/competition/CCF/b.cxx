/*
 * @Author: cgp 2986779260@qq.com
 * @Date: 2024-09-09 16:33:15
 * @LastEditors: cgp 2986779260@qq.com
 * @LastEditTime: 2024-09-10 11:04:43
 * @FilePath: \CCF\b.cxx
 * @Description: algorithm
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, t;

void tranpose(vector<int> &M, int& n, int& m)
{
    // 矩阵转置
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(M[i * m + j], M[j * m + i]);
        }
    }
    swap(n, m);
}
void reshape(vector<int> &M, int p, int q)
{
}
int main()
{
    cin >> n >> m >> t;
    vector<int> M;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            M.push_back(x);
        }
    }

    while (t--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            // 形状重置
            n = a, m = b;
            // tranpose(M, n, m);
            // swap(n, m);
            cout << "reshape" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << M[i * m + j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else if (op == 2)
        {

            tranpose(M, n, m);
            cout << "n:" << n << " m:" << m << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << M[i * m + j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        else
        {
            // m = 3, n = 2
            cout << M[a * m + b] << endl;
        }
    }
    return 0;
}