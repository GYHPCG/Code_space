/*#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	 string A;
	int B;
	cin>>A>>B;
	 int Q=0;
	int R=0;
	int len=A.length();
	Q=(A[0]-'0')/B;
	if((Q&&))
	cout<<Q<<" "<<R;
	return 0;
}*/
	#include <stdio.h>
    #include <string.h>
    #define MAX 1001

    int main()
    {
        char arr[MAX] = { 0 };
        int div = 0;
        int len = 0;
        int ret = 0;
        scanf("%s", arr);
        scanf("%d", &div);
        len = (int)strlen(arr);
        for (int i = 0; i < len; i++)
        {
            if (i > 0 || (arr[i] - '0') / div != 0) //Ϊ���жϵ�һ�������
            {
                printf("%d", (ret * 10 + arr[i] - '0') / div);
            }
            ret = (ret * 10 + arr[i] - '0') % div; //��¼��һ��������
        }
        if (len == 1 && (arr[0] - '0') < div) //ֻ��һλ������С�ڱ�����
        {
            printf("0");
        }
        printf(" %d", ret);
        return 0;
    }

