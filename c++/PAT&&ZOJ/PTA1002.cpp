#include<cstdio>
#include<iostream>
using namespace std;
 
int main (){
    char num;
	int sum = 0, n1, n2, n3;
	while((num = getchar())!='\n'){
		sum += num - '0';
	}
    
    char convert[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    n1 = sum / 100;       //��λ���� 
    n2 = (sum / 10) % 10; //ʮλ���� 
    n3 = (sum%10) ;//��λ���� 
    
	if(n1 == 0 && n2 == 0){
        cout << convert[n3] << endl;    
    }else if(n1==0 && n2!=0){
        cout << convert[n2] << " " << convert[n3] << endl;
    }else {
        cout << convert[n1] << " " << convert[n2] << " " << convert[n3] << endl;
    }     
    
    return 0;
}
