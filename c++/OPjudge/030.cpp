#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
	private:bool x;
	public:
		MyCin():x(true){
		}
		operator bool()
		{
			return x;
		}
		MyCin& operator>>(int& n)
		{
			  if(!x)return *this;
			  cin>>n;
			  if(n==-1)x=false;
			  return *this;
		} 
		/*private:int judge;
		public:MyCin():judge(1){
		}
		MyCin& operator>>(int& n)
		{
			if(judge==0)return *this;
			cin>>n;
			if(n==-1)judge = 0;
			return *this;
		}
		operator int()
		{
			return judge;
		} */
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
