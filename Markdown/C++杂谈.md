# C++杂谈

## 1. Algorithm

### 1.1函数

#### 1.1.1求全排列的解法：

1. 1个人手写回溯算法模拟

```c++
//求全排列，用回溯算法,对字符串里面的字符
vector<string>res;
string path;
void backTrack(string& s, vector<bool>& used) {
    if (path.size() == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < (int) s.size(); ++i) {
        if (i > 0 && s[i] == s[i-1] && used[i-1] == true) continue;
        if(used[i] == false) {
            used[i] = true;
            path += s[i];
            backTrack(s,used);
            used[i] = false;
            path.pop_back();
        }
    }
}
std::vector<std::string> permutations(std::string s) {
  // Your code here
    int n = s.size();
    //去重，所以先排一下大小
    sort(s.begin(),s.end());
    vector<bool>used(n,false);
    backTrack(s,used);
    return res;
}
```

2. 调用库函数

   ==**std::next_permutation**====(**first,last**)==

   它用于将[first, last]范围内的元素重新排列到下一个字典上更大的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排序不同的排列。

3. ==**std**::**prev_permutation(first,last)**==

   它用于将[first, last)范围内的元素重新排列为上一个按字典顺序排列的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排列不同的排列顺序。

```c++
void Next_permutation(string s) {
    //next_permutation(first,end),每次只能找到比当前排列下一个的排列,同样的，prev_permutation()是比当前大的前一个排	//列
    //所以，要想获得所有的全排列，必须先sort(),然后循环里找。
    sort(s.begin(),s.end());
    do {
        res.push_back(s);
    } while(next_permutation(s.begin(),s.end()));
    //return res;
}
```







#### 1.1.2字符串格式化

1. **int sscanf( const char *format [,argument]... );**

   ```cpp
   string buf2{"12-78"};
       int str ;
       int str2;
       //要用c_str()函数将string转换为const char* 类型
       int n = sscanf(buf2.c_str(),"%d-%d",&str,&str2);
       cout << n << endl;// n = 2
       cout << str << " " << str2 << endl;// 12 78
   
   
   //注意事项，千万不要用string 类型去接收结果，否则无法运行
    string buf = "abc&dfrgh";
       string s1;
       // char s1[100];
       // char s2[100];
   	//字符串输入源可以是string类型，但要用c_str()函数转换成 const char*类型。
       sscanf(buf.c_str(),"%[^g]",s1);//这里的s1运行后就报错
       cout << s1 << endl;
   ```

2. **格式化规则可以支持==正则表达式==**，也可以选择scanf()函数化的格式规则来进行处理，但是要注意一下

   ```c++
    string buf = "abc&dfrgh";
       // string s1;
       char s1[100];
       // char s2[100];
       sscanf(buf.c_str(),"%[a-f]",&s1);//这里我希望得到a-f的字符，但是获取"abc"后，‘&’不在这个范围，然后函数就		会停止
       cout << s1 << endl;//abc
   ```

   

   ## [sscanf分割字符串用法总结](https://www.cnblogs.com/rere-whh/p/7608446.html)

   

   **基本用法**

   ```c++
   通过ssacnf()语句可以找到和它前面匹配的语句然后打印出后面需要的东西，基本格式为%[set],表示将接收一个由set指定格式的字符串，其中set表示可接受的字符集合。
     set一般有两种情况：
                    （1）%[^set]表示非，即在输入字符串中匹配不在set字符集合的所有字符，遇见set字符集中的字符即停止；
                    （2）%[set]，匹配输入字符串中所有在set字符集中的字符，遇见非set字符集的字符时即停止。
   
     如：
     sscanf(buf,"%[^&]",str);  //当输入的字符中出现"&"时停止匹配,如果输入hello&world,则str=hello;
     sscanf(buf,"%[^290#]",str); //当输入aidc＃ad时,则str=aidc,即当输入出现了"#"时不再将输入内容放入str;
     sscanf(buf,"%[dlza#i]",str) //  如果不是这几个字符则停止匹配，如当输入ai＃dcad时,str=ai#d,因为c不在[dlza#i]中.
   ```

   

     (1)如果要匹配"^"时,当然不能直接放在[]中,所以可以用%[ab^cd]这种方式,

     (2)当要匹配右方括号"]"时,应把其放在set中第一个位置，如"%[]abc]"表示匹配的字符集为{], a, b, c}，又如"%[^]abc]"表示匹配所有非"], a, b, c"中的字符

     (3)另外,还可以使用"-" 如%[a-z]表示只匹配abcd....yz等小写的字母;%[0-9]表示只匹配0,1,2...9等数字;

     (4) * 表示跳过.

     注意 :  “-”的字符只有在其左右两边都有有效字符时才有这个作用，否则被认为是普通字符，如“a-c-e-g”匹配的字符为｛a, b, c, -, e, f, g｝，这样也为输入“-”字符提供了方法。

   
     **sscanf函数的高级用法**


     sscanf与scanf类似，都是用于输入的，只是后者以屏幕(stdin)为输入源，前者以固定字符串为输入源。
     函数原型：
      int sscanf( const char *format [,argument]... );
      其中的format可以是一个或多个：{%[*][width][{h|l|I64|L}]type|' '|'\t'|'\n'|非%符号}，   注：     1)、 * 亦可用于格式中, (即 %*d 和 %*s) 加了星号 (*) 表示跳过此数据不读入 (也就是不把此数据读入参数中)     2)、{a|b|c}表示a,b,c中选一，[d],表示可以有d也可以没有d。 

   ​     3）、width:宽度，一般可以忽略，用法如：
   ​      

   ```c++
       const char sourceStr[] = "hello, world";
             char buf[10] = {0};
             sscanf(sourceStr, "%5s", buf);  //%5s，只取5个字符
             cout << buf<< endl;
   ```

   ​          结果为:hello
   ​     4）、{h|I|I64|L}:参数的size,通常h表示单字节size，I表示2字节 size, L表示4字节size(double例外),l64表示8字节size。
   ​     5）、type :这就很多了，就是%s,%d之类。
   ​     6）、特别的：%*[width] [{h|l|I64|L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值。如：
   ​         const char sourceStr[] = "hello, world";
   ​         char buf[10] = {0};
   ​          sscanf(sourceStr, "%*s%s", buf);  //%*s表示第一个匹配到的%s被过滤掉，即hello被过滤了
   ​          cout << buf<< endl;
   ​         结果为:world
   ​      7）、支持集合操作：
   ​          %[a-z] 表示匹配a到z中任意字符，贪婪性(尽可能多的匹配)
   ​          %[aB'] 匹配a、B、'中一员，贪婪性
   ​          %[^a]  匹配非a的任意字符，贪婪性
   ​          和正则表达式很相似，而且仍然支持过滤，即可以有%*[a-z]。
   ​      例子：
   ​      1. 常见用法。

   ```c++
      char buf[512] = {0};
             sscanf("123456 ", "%s", buf);
             printf("%s\n", buf);
             结果为：123456 
   ```

   ​      2. 取指定长度的字符串。如在下例中，取最大长度为4字节的字符串。
   ​         

   ```c++
    sscanf("123456 ", "%4s", buf);
             printf("%s\n", buf);
             结果为：1234 
   ```

   ​      3. 取到指定字符为止的字符串。如在下例中，取遇到空格为止字符串。
   ​        

   ```c++
     sscanf("123456 abcdedf", "%[^ ]", buf);
             printf("%s\n", buf);
             结果为：123456 
   ```

   ​       4. 取仅包含指定字符集的字符串。如在下例中，取仅包含1到9和小写字母的字符串。
   ​        

   ```c++
     sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
             printf("%s\n", buf);
             结果为：123456abcdedf 
   ```

   ​       5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。
   ​         

   ```c++
    sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
             printf("%s\n", buf);
             结果为：123456abcdedf 
             sscanf("[iios/12DDWDFF@122](mailto:iios/12DDWDFF@122)", "%*[^/]/%[^@]", buf);
             printf("%s\n", buf);
     		  结果为：12DDWDF
          7、给定一个字符串““hello, world”，仅保留world。（注意：“，”之后有一空格）
             sscanf(“hello, world”, "%*s%s", buf); 
             printf("%s\n", buf);
             结果为：world
             %*s表示第一个匹配到的%s被过滤掉，即hello被过滤了，如果没有空格则结果为NULL。 
          8、分隔字符串2006:03:18
             int a, b, c;
             sscanf("2006:03:18", "%d:%d:%d", a, b, c); 
          9、分隔字符串2006:03:18 - 2006:04:18
             char sztime1[16] = "", sztime2[16] = "";
             sscanf("2006:03:18 - 2006:04:18", "%s - %s", sztime1, sztime2); 
         10、分隔字符串2006:03:18-2006:04:18
             char sztime1[16] = "", sztime2[16] = "";
              sscanf("2006:03:18-2006:04:18", "%[0-9,:] - %[0-9,:]", sztime1, sztime2);
         仅仅是取消了‘-’两边的空格，却打破了%s对字符串的界定format-type中有%[]这样的type  field。如果读取的字符串，不是以空格来分隔的话，就可以使用%[]。%[]类似于一个正则表达     式。 [a-z]表示读取a-z的所有字符，[^a-z]表示读取除a-z以外的所有字符。 
         
      sscanf的功能很类似于正则表达式, 但却没有正则表达式强大,所以如果对于比较复杂的字符串处 理,建议使用正则表达式.
   ```

​    

   正则表达式的基本用法：
         1、“.”为通配符，表示任何一个字符，例如：“a.c”可以匹配“anc”、“abc”、“acc”；
         2、“[]”，在[]内可以指定要求匹配的字符，例如：“a[nbc]c”可以匹配“anc”、“abc”、"acc"；但不可以匹配“ancc”,a到z可以写成[a-z],0到9可以写成[0-9];
         3、数量限定符号，表示匹配次数（或者叫做长度）的符号,包括：
           “*” 0次或者多次 
           “+” 1次或者多次
           “?” 0次或者1次
           “{n}”  匹配n次，n为整数
           “{n,m}” 匹配从n到m之间的某个数的次数；n和m都是整数；
           “{n,}”  匹配n到无穷次之间任意次数；
           “{,m}”  匹配0到m之间任意次数；
            数量限定符号放到匹配格式的后面，例如：电话号码：024-84820482，02484820482(假设前面3或者4位，后面7或者8位，并且中间的减号可有可无)，都是符合规定的，那么可以         用如 下格式来匹配：[0-9]{3,4} \-? [0-9]{7,8}；注意：“\”为转义字符，因为“-”在正则表达式用有代表一个范围的意义，例如：前面所说的[0-9]，所以它需要转义字符“\”进行转义才可用；
        4、^为否符号，表示不想匹配的符号，例如：[^z][a-z]+可以匹配所有除"z"开头的以外的所有字
           如果^放到[]的外边则表示以[]开头的字符串；^[az][a-z]+表示a或者z开头的长度大于等于2的英文字符串；
        5、“|”或运算符，例如：a[n|bc|cb]c可以匹配“abcc”,“anc”,“acbc”；
        6、“$”以它前面的字符结尾的；例如：ab+$就可以被“abb”，“ab”匹配；
        7、一些简单表示方法：\d表示[0-9];\D表示[^0-9];\w表示[A-Z0-9];\W表示[^A-Z0-9];\s表示[\t\n\r\f],就是空格字符包括tab，空格等等;\S表示[^\t\n\r\f]，就是非空格字符;

## 2. 一些语法

### 1. cvm修饰符

1. **const修饰符**：定义程序用到的数字、字符串常量、代替宏定义
   * 从

## 3.标准库

### 一.string类

1. **认识**：首先认识一下字符串，string其实不是一个真正的“类型”，而是模板类basic_string的特化形式

   是一个typedef:

   ```c++
   using string = std::basic_string<char>;//string其实是一个别名
   ```

2. **简单操作**：

   ```c++
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
   ```

   **注意**：string的接口比较复杂，除了字符串操作，花园begin()，end()，push_back()等类似容器的操作，会使人容易把它当成一个”字符串容器“，但==字符串和容器完全是两个不同的概念==，存储的应该是有关系的文本，如若没有关系，建议使用vector<char>来存取

3. **字面量操作**：c++11为方便使用字符串，新增**字面量后缀 "s"**,明确表示string类型，可以使用 **auto**关键字推出string类型，而不再是以往推出的传统的c风格的数组，使用如下：

   ```c++
       //字面量后缀 "s",明确表示string类型
       //需要打开命名空间才能使用 using namespace std::literals::string_literals;
       
       auto str1 = "qwer"; //实际auto推出的类型为 const char[]
       auto str2 = "qwert"s; //在结尾添加后缀“s”,则推出sting
       //添加s后临时变量可以直接调用string的成员函数
   
       cout << "hello"s.size() << endl; 
   ```

4. **原始字符串**：由于在c++中，字符有 "转义" 的用法，所以很多时候在字符前面添加了一个 “\”，就会使得后面的字母发生转义。但是有时候我们不想转义，想原样输出，就得转义很麻烦，而 原始字符串的出现，就是为了处理这一类情况和正则表达式，具体语法如下

   ```c++
       //比原来的引号就多了一个大写字母R和一对圆括号
       string s = R"(Hello,world)";//输出为hello,world
   
       string sc2 = "\mklp"; //输出 mklp，如果我们要输出"\mklp"，则需要转义如下
       string sc = "\"\\mklp\"";//输出为"\mkp"
       cout << sc2 << endl;// sc2: mklp
       cout << sc << endl; // sc: "\mklp"
   
       string sc3 = R"("\mklp")"; //使用原始字符串
       cout << sc3 << endl; // sc3: "\mklp"，不用再去去转义
       //若要输出R"(mklp)"的话，则要特殊处理下，在圆括号（）两边加上“界定符”--“==”
       string sc4 = R"==(R"(mklp)")==";
       cout << sc4 << endl; //sc4: R"(mklp)"
   ```

5.  **字符串转换函数**：在处理字符串的时候，常常要将字符串和数字相互转换。但是以前只能使用 c函数 atoi()、atol()，而它们的参数是c字符串而不是string，转起来很麻烦。c++11添加了string的转换函数

   - stoi()、stol()、stoll()等将字符串转换成整数
   - stof()、stod()等将字符串转换成浮点数
   - to_string()把整数、浮点数转换为字符串。

   ```c++
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
   ```

   c++17还新增了一个 **string_view** 字符串视图类，内部指保存了一个指针和长度，无论是拷贝，还是修改，都比 **string** 的成本大大减小。
