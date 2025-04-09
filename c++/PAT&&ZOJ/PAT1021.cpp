#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[1001];
	scanf("%s",a) ;
	int l = strlen(a);
	printf("%d\n", l);
	int li = 0, y = 0, e = 0, s = 0, si = 0, w = 0, liu = 0, q = 0, b = 0, j = 0;
	for (int i = 0;i<l;  i++)
	{
		int x = a[i]-'0';
		switch (x)
		{
		case 0:li++; break;
		case 1:y++; break;
		case 2:e++; break;
		case 3:s++; break;
		case 4:si++; break;
		case 5:w++; break;
		case 6:liu++; break;
		case 7:q++; break;
		case 8:b++; break;
		case 9:j++; break;
		//default:printf("..."); break;

		}
	}
	if (li > 0)printf("0:%d\n", li);
	 if (y > 0)printf("1:%d\n", y);
	 if (e > 0)printf("2:%d\n", e);
	 if (s > 0)printf("3:%d\n", s);
	 if (si > 0)printf("4:%d\n", si);
	 if (w > 0)printf("5:%d\n", w);
	 if (liu > 0)printf("6:%d\n", liu);
	if (q > 0)printf("7:%d\n", q);
	if (b > 0)printf("8:%d\n", b);
	if (j > 0)printf("9:%d\n",j);


	return 0;
}
