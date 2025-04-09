#include<stdio.h>
#include<string.h>
#define N 50
int ID[N],score[N];
int ReadScore();
int PrintScore(int ID[],int score[],int count);
int SortScore(int ID[],int score[],int count); 
int SortID(int ID[],int score[],int count); 
int search(int ID[],int score[],int count); 
void StaScore(int ID[],int score[],int count); 
int main()
{
	int ReadScore();
	int sum = 0,count = 0, i = 0,j = 0,n = 0;
	double ave = 0.0;
	count=ReadScore();
	printf("学生人数为：%d\n",count); 
	search(ID,score,count);
	for(i=0,sum=0;i<count;i++) sum+=score[i];
	ave=(float)sum/count;
	printf("课程总分=%d\n",sum);
	printf("平均分=%.3f\n",ave); 
	SortScore(ID,score,count);
	SortID(ID,score,count);

	StaScore(ID,score,count);		
}
int ReadScore()
{
	printf("请录入每个学生的学号和成绩,以一个负数结束\n");
    int i,count;
    for(i=0;i<N;i++)
	{
		printf("学号:");
	    scanf("%d",&ID[i]);
	    if(ID[i]<0) break;
	    printf("成绩:");
		scanf("%d",&score[i]);
		fflush(stdin);
    } 
    count=i;
    return count; 
}
int PrintScore(int ID[],int score[],int count) 
{
	int i;
	for(i=0;i<count;i++) printf("学生学号:%d  成绩:%d\n",ID[i],score[i]);
}
int SortScore(int ID[],int score[],int count)
{
    int i,j,m,n,k;
    printf("---------------名次表---------------\n");
	for (i = 0; i < count - 1; i++) {
		k = i;
	    for (j = i + 1; j< count; j++)
	    if (score[j] > score[k]) k = j;
		m = score[k];
		score[k] = score[i];
		score[i] = m;
		n = ID[k];
		ID[k] = ID[i];
		ID[i] = n;
		
	}
	PrintScore(ID,score,count);
}
int SortID(int ID[],int score[],int count)
{
	int i,j,m,n,k; 
	printf("---------------学号成绩表---------------\n");
	for(i=0;i<count-1;i++)
	{
		k=i;
	    for(j=i+1;j<count;j++)
	    if (ID[j]<ID[k]) k=j;
		if(k!=i)	
		{
			m=score[k];
			score[k]=score[i];
			score[i]=m;
			n=ID[k];
			ID[k]=ID[i];
			ID[i]=n;
		}
	}
	PrintScore(ID,score,count);
}
int search(int ID[],int score[],int count)
{
	int i,j,m,n,x;
	for(i=0;i<count;i++) 
	{
		for(j=0;j<count-i-1;j++)
		{
			if(score[j]<score[j+1])
			{
			m=score[j];
			score[j]=score[j+1];
			score[j+1]=m;
			n=ID[j];
			ID[j]=ID[j+1];
			ID[j+1]=n;
		    }
		}	
	}
	printf("请输入要搜索的学生学号：");
	scanf("%d",&x) ;
	for(i=0;i<count;i++)
	{
	if(ID[i]==x) {printf("学生排名:%d   成绩:%d\n",i+1,score[i]);break;}
    }
}
void StaScore(int ID[],int score[],int count)
{
	int i,m,sta[5]={0};
	for(i=0;i<count;i++)
	{
		m=score[i]/10;
		switch(m)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:sta[0]++;break;
			case 6:sta[1]++;break;
			case 7:sta[2]++;break;
			case 8:sta[3]++;break;
			case 9:
			case 10:sta[4]++;break;
		}
	}
	printf("--------各等级类别人数及占比--------\n");
	printf("优秀有%d人   占比：%.2f%%\n",sta[4],(double)sta[4]/count*100);
	printf("良好有%d人   占比：%.2f%%\n",sta[3],(double)sta[3]/count*100);
	printf("中等有%d人   占比：%.2f%%\n",sta[2],(double)sta[2]/count*100);
	printf("及格有%d人   占比：%.2f%%\n",sta[1],(double)sta[1]/count*100);
	printf("不及格有%d人 占比：%.2f%%\n",sta[0],(double)sta[0]/count*100);
}
