#include<stdio.h>
int main()
{
	int N;
	scanf("%d\n",&N);
	int a[N];
	int i=0;
	int num1=0,num2=0;
	for(i=0;i<N;i++)
	{
	scanf("%d",&a[i]);
    }
    int j;
    for(i=0;i<N;i++)
	{
		if(a[i]>1)
		{
			int k=1;
		
	
	    for(j=2;j<a[i];j++)
		{
        if(a[i]%j==0){
        k=0;
		break;}
		
	   }
	   if(k!=0)
	   num2++;
	
}
}
    printf("%d ",num2);
     for(i=0;i<N;i++){
    	if(a[i]%2==0)
    	num1++;
	}
	
	printf("%d",num1);
	return 0;
}
