
#include <iostream>
#include <algorithm>
using namespace std;

int scores[11]={95,90,85,80,75,70,67,65,62,60,0};
double gpa[11]={4.3,4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.0,0.0};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int score{};
        cin >> score;
        double sum_gpa = 0;
        for(int i=0;i<=10;i++)
        {
            for(int j=0;j<=10;j++)
            {
                for(int k=0;k<=10;k++)
                {
                    for(int m=0;m<=10; m++)
                    {
                        if(scores[m]+scores[k]+scores[j]+scores[i]<=score)
                        {
                            sum_gpa=max(sum_gpa,gpa[m]+gpa[k]+gpa[j]+gpa[i]);
                        }
                    }
                }
            }
        }
        printf("%.1f\n",sum_gpa);
    }
}
