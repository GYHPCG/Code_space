//���ַ������򣬣�ð�����򷨣�
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void main()
{
	void sort(char* name[],int n);//��������
	void print(char* name[],int n);
	char* name[100];
	int j;
	for(j=0;;j++){
		name[j]=(char *)malloc(100*sizeof(char));
		scanf("%s",name[j]);
		if(strcmp(name[j],"*****")==0)break;
	}
	
	int n=j;
	sort(name,n);    //��������
	print(name,n);
 
}
//ð��������
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
//���ָ������Ԫ����ָ����ַ���
void print(char* name[],int n)
{
	

	
		printf("%s\n",name[0]);
	
}


