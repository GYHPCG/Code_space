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
	printf("ѧ������Ϊ��%d\n",count); 
	search(ID,score,count);
	for(i=0,sum=0;i<count;i++) sum+=score[i];
	ave=(float)sum/count;
	printf("�γ��ܷ�=%d\n",sum);
	printf("ƽ����=%.3f\n",ave); 
	SortScore(ID,score,count);
	SortID(ID,score,count);

	StaScore(ID,score,count);		
}
int ReadScore()
{
	printf("��¼��ÿ��ѧ����ѧ�źͳɼ�,��һ����������\n");
    int i,count;
    for(i=0;i<N;i++)
	{
		printf("ѧ��:");
	    scanf("%d",&ID[i]);
	    if(ID[i]<0) break;
	    printf("�ɼ�:");
		scanf("%d",&score[i]);
		fflush(stdin);
    } 
    count=i;
    return count; 
}
int PrintScore(int ID[],int score[],int count) 
{
	int i;
	for(i=0;i<count;i++) printf("ѧ��ѧ��:%d  �ɼ�:%d\n",ID[i],score[i]);
}
int SortScore(int ID[],int score[],int count)
{
    int i,j,m,n,k;
    printf("---------------���α�---------------\n");
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
	printf("---------------ѧ�ųɼ���---------------\n");
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
	printf("������Ҫ������ѧ��ѧ�ţ�");
	scanf("%d",&x) ;
	for(i=0;i<count;i++)
	{
	if(ID[i]==x) {printf("ѧ������:%d   �ɼ�:%d\n",i+1,score[i]);break;}
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
	printf("--------���ȼ����������ռ��--------\n");
	printf("������%d��   ռ�ȣ�%.2f%%\n",sta[4],(double)sta[4]/count*100);
	printf("������%d��   ռ�ȣ�%.2f%%\n",sta[3],(double)sta[3]/count*100);
	printf("�е���%d��   ռ�ȣ�%.2f%%\n",sta[2],(double)sta[2]/count*100);
	printf("������%d��   ռ�ȣ�%.2f%%\n",sta[1],(double)sta[1]/count*100);
	printf("��������%d�� ռ�ȣ�%.2f%%\n",sta[0],(double)sta[0]/count*100);
}
