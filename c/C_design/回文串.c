#include<stdio.h>
#include<string.h>
int main()
{
    int isPalindromicString(char s[]);
	char s[100];

	gets(s);

	if(isPalindromicString(s))

		printf("Yes");

	else

		printf("No");

	return 0;

}
int isPalindromicString(char s[])
{
	int n=strlen(s);
	int b=0,i;
	for(i=0;i<n/2;i++)
	{
	  if(s[i]==s[n-i-1])
	  b=1;
	  else 
	  b=0;
	}
	return b;
}
