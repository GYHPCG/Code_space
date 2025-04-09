#include <iostream>
//sscanf()从给定的字符串按照一定个人所想要的格式获取其中内容，支持scanf里面的格式和正则等
using namespace std;

int main()
{
    string buf{"hello&world"};
    string buf2{"12-78"};
    string str;
    //int str2;
    //要用c_str()函数将string转换为const char* 类型
    sscanf(buf.c_str(),"%[hlo]",&str);
    cout << str << endl;
    return 0;

}
