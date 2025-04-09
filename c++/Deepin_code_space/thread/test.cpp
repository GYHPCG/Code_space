/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-31 22:30:45
 * @LastEditors: CGPan
 * @LastEditTime: 2023-05-17 20:13:24
 */
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
/* 
“读而不写”就不会有数据竞争。所以在c++多线程编程读取const变量总是安全的，对类调用const
成员函数，对容器调用只读算法也总是线程安全的。
多线程开发实践，在c++里有四个基本的工具：仅调用一次，线性局部存储，原子变量和线程对象
*/

//避免多线程初始化函数多次运行，声明一个once_flag类型的变量，最好是静态，全局的（线程可见）
//，作为初始化的标志
static std::once_flag flag; //全局初始化的标志

//然后调用专门的call_once()函数，以函数式编程的方式，传递这个标志和初始化函数。
//这样c++就会保证，即使多个线程重入call_once(),也只能有一个线程会运行初始化
int main()
{
    //使用lambda来模拟实际的线程函数
    int a = 1;
    auto f = [&]() {
        // std::call_once(flag, []() {
        //     cout << "only once" << endl;
        // }
        for (int i = 0; i <= 50; ++i)
        {
            a += 1;
        }
        //);
    };

    thread t1(f);
    t1.join();
    thread t2(f);
    t2.join();

    cout << a << endl;
    //线性局部存储
    //读写全局（或者局部静态）变量是另一个比较常见的数据竞争场景，因为共享数据，
    //多线程操作时就有可能导致状态不一致
    //全局变量并不一定是必须共享的。可能仅仅是为了方便线程传入传出数据，或者是本地cache，
    //而不是为了共享所有权。线程多占所有权，不应该在多线程之间共同拥有
    //该功能在c++里由关键字thread_local实现，它是一个和static，extern同级的变量存储说明
    //，有thread_local标记的变量在每个线程里都会有一个独立的副本，是“线程独占”的，所以就不会
    //有竞争读写的问题
    // 如下：
    // thread_local int n = 0; //定义了一个线程独占变量
    // //int n = 0;
    // auto f = [&](int x) {
    //     n += x;
    //     cout << n << " ";
    // };
    // thread f1(f,10);
    // f1.join();
    // thread f2(f,20);
    // f2.join();//10, 20两个线程互不干扰
    // cout << "-----原子变量------" << endl;
    
    
    return 0;

}
