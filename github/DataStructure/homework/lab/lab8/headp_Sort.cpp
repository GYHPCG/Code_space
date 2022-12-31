/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-14 16:19:49
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-14 18:33:10
 */
#include <iostream>

using namespace std;

#define MAXSIZE 100  /* 用于要排序数组个数最大值*/
typedef struct
{
	int r[MAXSIZE+1];	
	int length;			/* 用于记录顺序表的长度 */
}HeapArr;

void swap(HeapArr *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}

void HeapAdjust(HeapArr *L,int s,int m)
{ 
	int temp,j;
	temp = L->r[s];
	for(j = 2*s;j <= m;j *= 2) /* 沿关键字较大的孩子结点向下筛选 */
	{
		if(j < m && L->r[j] < L->r[j+1])
			++j; /* j为关键字中较大的记录的下标 */
		if(temp>=L->r[j])
			break; /* rc应插入在位置s上 */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; /* 插入 */
}

/*  对顺序表L进行创建最大堆 */
void CreatHeap(HeapArr *L)
{
	int i;
	for(i=L->length/2;i>0;i--) /*  把L中的r构建成一个大顶堆 */
		 HeapAdjust(L,i,L->length);

}
void HeapSort(HeapArr& L) {
	CreatHeap(&L);
	for (int i = L.length; i > 1;--i) {
		swap(&L,1,i);
		HeapAdjust(&L,1,i-1);
	}
}
void FirstHeapSort(HeapArr& L) {
	CreatHeap(&L);
	for (int i = L.length; i > 1;--i) {
		swap(&L,1,i);
		cout << "第一次堆顶元素的输出为："<< L.r[i] << endl;
		HeapAdjust(&L,1,i-1);
		break;
	}
}
void print(HeapArr L)
{
	int i;
	for(i=1;i< L.length;i++)
		printf("%d,",L.r[i]);
	printf("%d",L.r[i]);
	printf("\n");
}
void FirstPrint(HeapArr L) {
	for (int i = 1; i < L.length - 1; ++i) {
		printf("%d,",L.r[i]);
	}
	printf("%d\n",L.r[L.length - 1]);
}
int main()
{
    int arr[] = {3,1,4,1,5,9,2,6};
    HeapArr hp;
	for (int i = 0; i < 8; ++i) {
		hp.r[i+1] = arr[i];
		++hp.length;
	}
	printf("建大根堆，并输出该最大堆序列:\n");
	CreatHeap(&hp);
	print(hp);
	FirstHeapSort(hp);
	printf("进行一次堆顶元素的输出(删除),输出经过1次堆顶输出后的序列\n");
	FirstPrint(hp);
	HeapSort(hp);
	printf("输出堆排序输出的结果：\n");
	print(hp);
    return 0;

}
