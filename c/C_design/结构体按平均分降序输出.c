#include<stdio.h>
struct stu
{
	char name[20];
	double a;
	double b;
	double c;
	double aver;
}p[3],temp;
int main()
{
	int i;
	for(i=0;i<3;i++){
		scanf("%s%lf%lf%lf%lf",p[i].name,&p[i].a,&p[i].b,&p[i].c);
	}
	for(i=0;i<3;i++){
		p[i].aver=(p[i].a+p[i].b+p[i].c)/3;
	}
	
	for(i=0;i<3;i++){
		int k=0;
		for(k=0;k<3-i-1;k++){
			if(p[k].aver<p[k+1].aver){
				temp=p[k+1];p[k+1]=p[k];p[k]=temp;
			}
		}
	}
	for(i=0;i<3;i++){
		printf("%s %.2f\n",p[i].name,p[i].aver);
	}
	return 0;
}
