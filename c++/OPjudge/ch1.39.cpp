#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[100000];
	cin.getline(a,100000);
	int l=strlen(a);
	int i,k;
	int c[100000];
	for (k = 0; k < l; k++) {
		for (i = 0; i < l; i++) {
			if (a[k] == a[i]) {
				c[k]++;
			}
		}
		if (c[k] == 1) 
			break;
		
	}
 
	if (k == l )
		cout<<"no";
	 else 
		cout<<a[k]; 
		return 0;
}
	
	
	/*for(i=0;i<l;i++)
	{
		for(k=0;k<l;k++)
		{
			if(a[i]==a[k]) 
			{
			c[i]++;
			}
		}
		if(c[i]==1) {
		break; }
	}
	if(i==l)
	printf("no");
	else{
		  printf("%c",a[i]);} 
	return 0;
}
/* 
#include <stdio.h>
#include <string.h> 
int main() {
	char a[100000];
	gets(a);
 
	int i;
	int k;
	int l=strlen(a);
	int c[100000];
	for (k = 0; k < l; k++) {
		for (i = 0; i < l; i++) {
			if (a[k] == a[i]) {
				c[k]++;
			}
		}
		if (c[k] == 1) {
			break;
		}
	}
 
	if (k == l ){
		printf("no");
	} else {
		printf("%c", a[k]);
	}
	return 0;
}  */

