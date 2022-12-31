/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-07 07:24:08
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-07 07:32:13
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>

int main()
{
    // 定义变量 x 和 y，表示爱心的横坐标和纵坐标
    int x, y;

    // 设置输出的字符颜色为红色
    std::cout << "\033[31m";

    // 通过循环实现动态运行效果
    while (true)
    {
        // 随机生成一个在屏幕范围内的坐标
        x = rand() % 50;
        y = rand() % 25;

        // 输出一个爱心的字符，并在它前后加上空格，用来清除上一次的爱心
        std::cout << " " << char(3) << " " << std::endl;

        // 移动光标到新的坐标位置
        std::cout << "\033[" << y << ";" << x << "H";

        // 延时 10 毫秒，调整爱心的运动速度
        usleep(10000);
    }

    return 0;
}
