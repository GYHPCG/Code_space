#include <iostream>

using namespace std;

constexpr int N = 50; //进程
constexpr int M = 100; //表示资源

int Available[M]; //可利用资源向量Available ,是个含有m个元素的数组，其中的每一个元素代表一类可利用的资源数目。如果Available[j] = K，则表示系统中现有Rj类资源K个。
int Allocation[N][M];  //已经分配矩阵
int Need[N][M];        //进程需求矩阵
int Request[N][M];     //M个进程还需要N类资源的资源量
bool Finish[N];
int p[N];    //已完成的进程数目
int m, n;   //M个进程,N类资源
 
//安全性算法
int Safe()
{
	cout << "\tWork" << "\t\tNeed" <<"\t\tAllocation" << "\t\twork+Allocation" << "\t\t" << "Finish" << "\n";
	
	int i, j, l = 0;
	int Work[M]; //工作向量
	for (i = 0; i < n; i++)
		Work[i] = Available[i];//在执行安全算法开始时，可提供的各类资源数目=系统现有各类资源数目;Work=Available; 
	for (i = 0; i < m; i++)
		Finish[i] = false;//表示系统是否有足够的资源分配给进程,初始化进程为0，表示都还未完成
	for (i = 0; i < m; i++)
	{
		if (Finish[i] == true)//工作向量等于1,进程执行
			continue;
		else//检查还未完成的进程
		{
			for (j = 0; j < n; j++)//检查进程中资源和系统所剩资源
			{
				if (Need[i][j] > Work[j])
					break;
			}//说明编号i的进程资源需求少于目前系统剩下的资源, 分配资源
			if (j == n)
			{
				cout << "P" << i<< "\t";
				for (int x = 0; x< n; x++)
					cout << Work[x] << "  ";
				cout << "\t";
				for (int x = 0; x < n; x++)
					cout << Need[i][x] << "  ";
				cout << "\t";
				for (int x = 0; x < n; x++)
					cout << Allocation[i][x] << "  ";
				cout << "\t\t";
				for (int x = 0; x < n; x++) {
					cout << Work[x] + Allocation[i][x]<<"  ";
				}
				cout << "\t\t";
				Finish[i] = true;
				cout << "true" << endl;
				cout << endl;
				for (int k = 0; k < n; k++)
					Work[k] = Work[k] + Allocation[i][k];//直至完成，并释放出分配给它的资源，故应执行可提供资源数量更新
				p[l++] = i;//p记录已经完成的进程数目
				i = -1;
			}
			else continue;
		}
		if (l == m)
		{
			cout << "系统是安全的" << "\n";
			cout << "系统安全序列是:\n";
			for (i = 0; i < l; i++)
			{
				cout <<"p"<< p[i];
				if (i != l - 1)
					cout << "-->";
			}
			cout << "\n";
			return 1;
		}
	}
	return 0;
}
 
//银行家算法
int banker()
{
	int i, j, mi;
	cout << "进程数: ";
	cin >> m;
	cout << "资源的种类: ";
	cin >> n;
	cout << "按照" << m << "x" << n << "矩阵输入Allocation数组" << endl;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
            cin >> Allocation[i][j];
 
	cout << "按照" << m << "x" << n << "矩阵输入Need数组" << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Need[i][j];//分配矩阵
		}
	}
	cout << "请输入各个资源空闲的数目Available数组:\n";
	for (i = 0; i < n; i++)
		cin >> Available[i];
	cout << "\n\n";
	Safe();
	cout << "\n\n\n";
	
	while (1)
	{
		int flag = 0;
		cout << "输入要申请的资源的进程号：（第一个进程号为0，第二个进程号为1，依此类推）\n";
		cin >> mi;
		cout << "输入进程所请求的各个资源的数量\n";
		for (i = 0; i < n; i++)
			cin >> Request[mi][i];
		for (i = 0; i < n; i++)
		{
 
			if (Request[mi][i] > Need[mi][i])//所请求资源数超过进程的需求量！
			{
				cout << "需求申请超出最大需求值\n\n\n";
				flag = 1;
			}
			if (Request[mi][i] > Available[i])//所请求资源数超过系统所有的资源数！
			{
				cout << "系统无足够资源，P"<<mi<<"阻塞等待\n\n\n";
				flag = 1;
			}
		}
		if (flag ==0) {
			
			for (i = 0; i < n; i++)
			{
				Available[i] = Available[i] - Request[mi][i];//可利用资源=可利用资源-进程需要
 
				Allocation[mi][i] = Allocation[mi][i] + Request[mi][i];//已分配资源=已分配资源+进程需要
 
				Need[mi][i] = Need[mi][i] - Request[mi][i];//进程还需资源=进程还需资源-进程需要
			}
			if (Safe()) {//存在安全序列
				cout << "同意分配请求\n\n\n";
				for (i = 0; i < n; i++)
				{
					Available[i] = Available[i] + Allocation[mi][i];//可利用资源=可利用资源-进程需要
				}
			}
			else//不存在安全序列，恢复资源
			{
				Available[i] = Available[i] + Request[mi][i];//可利用资源=可利用资源-进程需要
 
				Allocation[mi][i] = Allocation[mi][i] - Request[mi][i];//已分配资源=已分配资源+进程需要
 
				Need[mi][i] = Need[mi][i] + Request[mi][i];//进程还需资源=进程还需资源-进程需要
				cout << "不存在安全序列,P"<<mi<<"等待，你的请求被拒绝…\n\n\n";
			}
			for (i = 0; i < m; i++)
				Finish[i] = false;
		}
 
	}
	return 0;
}

int main()
{
	
	banker();

	return 0;
}