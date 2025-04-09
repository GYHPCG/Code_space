//对字符串排序，（冒泡排序法）
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void main()
{
	void sort(char* name[],int n);//函数声明
	void print(char* name[],int n);
	char* name[100];
	int j;
	for(j=0;;j++){
		name[j]=(char *)malloc(100*sizeof(char));
		scanf("%s",name[j]);
		if(strcmp(name[j],"*****")==0)break;
	}
	
	int n=j;
	sort(name,n);    //函数调用
	print(name,n);
 
}
//冒泡排序函数
void sort(char* name[],int n)
{
	char* temp;
	int i,j;
	for(i=0;i<n-1;i++) 
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcmp(name[j],name[j+1])<0)
			{
				temp=name[j];
				name[j]=name[j+1];
				name[j+1]=temp;
			}
		}
	}
}
//输出指针数组元素所指向的字符串
void print(char* name[],int n)
{
	

	
		printf("%s\n",name[0]);
	
}


