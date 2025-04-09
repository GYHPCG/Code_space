/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-29 15:42:46
 * @LastEditors: CGPan
 * @LastEditTime: 2023-01-01 02:14:07
 */
#include <iostream>
#include <string>
using namespace std;
/*
本次代码旨在对c++中string类进行一个简单而又完整的学习
首先认识一下字符串，string其实不是一个真正的“类型”，而是模板类basic_string的特化形式
是一个typedef:
using string = std::basic_string<char>;//string其实是一个别名

*/
int main()
{
    //功能支持简单测试
    string s = "hello,wolrd";
    //获取长度
    cout << s.size() << " " << s.length() << endl;
    //比大小
    cout << (s > "hea") << endl;
    //获取字串
    auto s1 = s.substr(0,2);//意为从第0个下标开始的2个字符组成的字符串
    cout << s1 << endl;
    //下标访问
    cout << s[1] << " " << s.at(1) << endl;
    //查找字符串,string::npos为找不到，找到，返回第一个的索引
    cout << (s.find("llo") == string::npos) << endl;

    cout << "------字面量后缀操作-------" << endl;
    //字面量后缀 "s",明确表示string类型
    //需要打开命名空间才能使用 using namespace std::literals::string_literals;
    
    auto str1 = "qwer"; //实际auto推出的类型为 const char[]
    auto str2 = "qwert"s; //在结尾添加后缀“s”,则推出sting
    //添加s后临时变量可以直接调用string的成员函数

    cout << "hello"s.size() << endl; 
    
    cout <<"----原始字符串----" << endl;
    
    string sc2 = "\mklp"; //输出 mklp，如果我们要输出"\mklp"，则需要转义如下
    string sc = "\"\\mklp\"";//输出为"\mkp"
    cout << sc2 << endl;// sc2: mklp
    cout << sc << endl; // sc: "\mklp"

    string sc3 = R"("\mklp")"; //使用原始字符串
    cout << sc3 << endl; // sc3: "\mklp"，不用再去去转义
    //若要输出R"(mklp)"的话，则要特殊处理下，在圆括号（）两边加上“界定符”--“== ==”
    string sc4 = R"==(R"(mklp)")==";
    cout << sc4 << endl; //sc4: R"(mklp)"

    string str_num = "123";
    //int int_num = atoi(str_num);//error: no function convent "string" to "const char*";
    int int_num = stoi(str_num);
    cout << int_num << endl; // 123

    string str_num1 = "123.789";
    double dou_num = stod(str_num1);
    cout << dou_num << endl; // 123.789

    int k = 123456;
    string sk = to_string(k);
    cout << sk << endl; // 123456
    return 0;

}