/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct st{
	char id[20];
	int age;
}p[100];
int main()
{
	  int n,i,j;
	  cin>>n;
	  for(i=0;i<n;i++)
	  cin>>p[i].id>>p[i].age;
	  for(i=0;i<n-1;i++){
	  	int tem=i;
	  	for(j=i+1;j<n;j++){
	  		if(p[j].age>=60)
	  		 if(p[tem].age>=60)
	  		    {
	  		    	if(p[j].age>p[tem].age)
	  		    	 tem=j;
				  }
		  }
	  }
	  for(i=0;i<n;i++)
	  {
	  	cout<<p[i].id<<" "<<p[i].age<<endl;
	  }
	  return 0;
} */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    struct bingren
    {
        string id;   //��¼id 
        int age;    //��¼���� 
        int que;    //��¼�Ǽ��Ⱥ�˳�� 
    }b[202];
    bingren t;
    int n,q=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b[i].id>>b[i].age;
        q++;
        b[i].que=q;    //��¼˭������ 
    }

    for(int i=0;i<n-1;i++)   
        {
            for(int j=i+1;j<n;j++)
            {
                if(b[i].age>=60&&b[i].age<b[j].age)  //���������60��Ľ������� 
                {
                       t=b[i];
                       b[i]=b[j];
                       b[j]=t;
                 }
                 else if(b[i].age==b[j].age&&b[i].que>b[j].que)   //���������ͬ�����Ǽ��Ⱥ�˳������ 
                    {
                        t=b[i];
                       b[i]=b[j];
                       b[j]=t;
                     } 
             }
         }
    for(int i=0;i<n;i++)   //�������������60 
    {
        if(b[i].age>=60)
        {
            cout<<b[i].id<<endl;    
        }
    }
    for(int i=0;i<n;i++)   //����������С��60 
    {
        if(b[i].age<60)
        {
            cout<<b[i].id<<endl;    
        }
    }
    return 0;
}



