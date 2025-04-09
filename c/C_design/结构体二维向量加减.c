#include<stdio.h>
#include<math.h>
struct erwei
{
	double x;
	double y;
}a[2];
int main()
{
	double x,y;
	int i;
	for(i=0;i<2;i++)
	{
	
	scanf("%lf %lf",&a[i].x,&a[i].y);
	
    }
    x=a[0].x-a[1].x,
	y=a[0].y-a[1].y;
	if(fabs(x)<0.05)
	  x=0.0;
	if(fabs(y)<0.05)
	  y=0.0;
    printf("(%.1f, %.1f)",x,y);
    
	
	return 0;
}
