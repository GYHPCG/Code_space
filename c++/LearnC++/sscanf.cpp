#include <iostream>
//sscanf()�Ӹ������ַ�������һ����������Ҫ�ĸ�ʽ��ȡ�������ݣ�֧��scanf����ĸ�ʽ�������
using namespace std;

int main()
{
    string buf{"hello&world"};
    string buf2{"12-78"};
    string str;
    //int str2;
    //Ҫ��c_str()������stringת��Ϊconst char* ����
    sscanf(buf.c_str(),"%[hlo]",&str);
    cout << str << endl;
    return 0;

}
