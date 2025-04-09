#include<stdio.h>
struct student
{
	char name[20];
	float score[3];
	float aver;
};
int main()
{
	void input(struct sudent stu[]);
	struct student max(struct student stu[]);
	void print(struct student stu);
	struct student stu[3],*p=stu;
	input(p);
	print(max(p));
	return 0;
}
void input(struct sudent stu[])
{
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%s %f %f %f",&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],);
		stu[i].aver=(stu[i].score+stu[i].score[1]+stu[i].score[2])/3.0;
	}
}
struct student max(struct student stu[])
{
	int i,m=0;
	for(i=0;i<3;i++)
	{
		if(stu[i].aver>stu[m].aver) m=i;
	}
	return stu[m];
}
void print(struct student stu)
{
	printf("%s %.2f",stu.name,stu.aver);
}
