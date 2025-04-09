/*#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,sum;
	cin>>n;
	int a1=1,a2=2;
	int i;
	while(n--)
	{
		cin>>x;
		if(x==1)cout<<a1<<endl;
		else if(x==2)cout<<a2<<endl;
		else {
			for (i=3;i<=x;i++)
			 {
			sum=2*a2+a1;
			a1=a2;
			a2=sum;
			 }
			
		     }
		     cout<<sum<<endl;
	}
	
	return 0;
}*/
/*#include <iostream>
#include <cstdio>
using namespace std;
 
int pell(int N){
	if (N == 1){
		return 1;
	}
	else if (N == 2){
		return 2;
	}
	else{
		int f1 = 1,f2 = 2,f3;
		for (int i = 0;i < (N-2);i++){
			f3 = (2*f2 + f1) % 32767;
			f1 = f2;
			f2 = f3;
		}
		return f2;
	}
}
 
int main(){
	int n;
	int data;
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> data;
		cout << pell(data) << endl;
	}
	return 0;
} */
#include <cstdio>
#include <iostream>
using namespace std;

int tot, n, a[1000001];

int main() {
	a[1] = 1;
	a[2] = 2;
	cin >> tot;
	
	for (int i=3; i<=1000000; i++) {			// pellµÝÍÆ 
		a[i] = (2*a[i-1] + a[i-2]) % 32767;		// %32767£¬±ÜÃâ³¬³ö·¶Î§ 
	}
	
	while (tot--) {
		cin >> n;
		cout << a[n] << endl;
	}
	
	return 0;
}
