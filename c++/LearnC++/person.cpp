#include <iostream>

using namespace std;
struct Person 
{
    /* data */
    char* Name;
    int Age;
    double Weight;
};
int main()
{
    Person* p = new Person();
    p->Name = new char[20];//�����Ҽ��������������20��char
    cin >> p->Name >> p->Age >> p->Weight;
    cout << p->Name <<" "<< p->Age <<" "<< p->Weight << endl;
    delete[] p->Name;
    delete p;
    //int x = 9;
    //int b = 1;
    const volatile int x = 10;//const ���κ���Ҫ�ı䣬�ɼ�volatile���� 
    int *px  = (int*) &x;
    *px = 6;
	//px = b;
	cout << *px; 
    return 0;

}
//#include <algorithm> 
//#include <vector>
//#include <iostream>
//using namespace std;
//vector<int>  get(vector<int>& arr) {
//	sort(arr.begin(),arr.end());
//	vector<int> res {arr[arr.size()-1], arr[0]};//���size == 1,��ô���ֵ����Сֵ��ͬһ��
//return res;
//}
//int main()
//{
//	vector<int> arr{1,8,3,0};
//	vector<int>res = get(arr);
//	for(int i = 0; i < res.size(); ++i) {
//		cout << res[i] << " ";
//	}
//	return 0;
//} 
