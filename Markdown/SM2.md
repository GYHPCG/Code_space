### 四.国密SM2加密算法

#### 一.国密SM2概念：

SM2是国家密码管理局与于2010年12月17日发布的椭圆曲线公钥密码算法。是一种比RSA算法更先进安全的算法。再我国通常用来替代RSA算法。SM2是ECC算法的一种，基于椭圆曲线离散对数问题，计算复杂度是指数级，求解难度较大，同等安全程度要求下，椭圆曲线密码较其他公钥秒速昂发所需密钥长度小很多。

#### 二.加密算法流程：

#####1.大致加密流程如下图所示：

![image-20221219161105883](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219161105883.png)



##### 2.SM2公私钥

算法是基于数学的，SM2定义椭圆曲线上的群运算加减乘，公私钥 ==Pb = DbP==，(Pb为公钥，Db为私钥，P为基点)生成如下：

假设我们选定的椭圆曲线如下：

![倍点运算](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL211emlwaWFvL0dpdEh1YkltYWdlcy9tYXN0ZXIvZ21vYmpjL2dtb2JqYzAzLnBuZw)

1. 首选一条椭圆曲线，即固定 a、b 的值，假设选择的是上图所示曲线。

   ```c++
   //SM2椭圆曲线公式如下：
   y^2 = x^3 + ax + b(4a^3 + 27b^2 != 0)
   ```

2. 随机选择一个点 P 为基点，曲线做切线，经过 Q 点，切点 R1。

3. 基于 x 轴做 R1 的对称点 R，则 SM2 定义加法为 P + Q = R，这就是==**椭圆曲线加法**==。

4. 求 2 倍点，当 P = Q 时，即 P + P = R = 2P，则 R 是 P 的 2 倍点。

5. 求 3 倍点，3P = P + 2P = P + R，经过 P、R 做直线，交于椭圆曲线点 M1, 基于 x 轴对称点 M 则是 3 倍点，依次类推。

6. 求 d 倍点，假设我们同样次数为 d，运算倍点为 Q。

7. d 为私钥，Q 为公钥。所以私钥是一个大整数，公钥是一个点坐标。

##### 3.详细过程：



设需要发送的消息为比特串 M，klen 为 M 比特串的长度，加密步骤如下：

1. 用随机数发生器产生随机数 **k , 1<= k <=  n -1**

2. 计算椭圆曲线点 **C1 = [k]G = (x1，y1)**，并将 C1的数据类型转换为比特串

   1. **[K]G**：椭圆曲线上点 **G** 的 K 倍点，即[k]p = k 个p 相加，但是并不是一般意义上的代数运算，具体看上面==2.SM2公私钥==。

3. 计算椭圆曲线点 ==S = [h]Pb==，若 S 是无穷远点，则报错并退出

4. 计算椭圆曲线点 ==[k]Pb  = （x2，y2）==（Pb为公钥），并将坐标 X2,y2的数据类型转换为比特串

5. 计算 ==t = KDF(x2 || y2，klen)==，KDF函数具体操作如下。若 t 为全 0 的比特串，则返回 步骤 1,  重新开始计算。

   - **KDF()是密钥派生函数**，作用是从一个共享的秘密比特串中派生出密钥数据。密钥派生函数KDF需要调用密码杂凑函数**Hv**()（输出长度为V比特的杂凑值）

   - **KDF(Z，klen)计算流程**：

     1. **输入**：比特串Z，整数klen(表示要获得的密钥数据的比特长度，要求该值小于2^32 - 1)

     2. **输出**：长度为klen的密钥数据比特串K

     3. **执行如下：**

        ![image-20221219170614322](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219170614322.png)

6. 计算 ==C2  = M 异或 t==

7. 计算 ==C3 = Hash(x2 || M || y2)==，密码杂凑函数 Hash()用法如下:

   - **Hash(m)**：对长度为*l*(*l <* 2 ^64) 比特的消息*m*，SM3杂凑算法经过填充和迭代压缩，生成杂凑值，杂凑值长度

     为256比特。具体过程如下图所示。

     其中用到的符号代表和函数具体为：

     1. ![image-20221219230944697](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219230944697.png)

        ![image-20221219231002351](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219231002351.png)

        ![image-20221219231124344](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219231124344.png)

     2. **填充**：假设消息**m** 的长度为**l** 比特。首先将比特“1”添加到消息的末尾， 再添加**k** 个“0”，**k**是满 足l + 1 + k = 448mod512 的最小的非负整数。然后再添加一个64位比特串， 该比特串是长度**l**的二进 制表示。填充后的消息m\  的比特长度为512的倍数。

     例如：对消息01100001 01100010 01100011，其长度l=24，经填充得到比特串：

     ![image-20221219225307411](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219225307411.png)

     3. **迭代压缩**：

        1. 迭代过程：

           ![image-20221219225618906](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219225618906.png)

        2. 消息扩展：

           ![image-20221219225932987](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219225932987.png)

        3. 压缩函数：

           ![image-20221219230014590](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219230014590.png)

     4. **杂凑值**：

        ![image-20221219230829636](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219230829636.png)

8. 输出密文 ==C = C1 || C2 || C3==

    