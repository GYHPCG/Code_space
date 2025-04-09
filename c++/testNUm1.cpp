/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2022-09-26 20:48:38
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-03-10 13:35:54
 */
#include <stdio.h>

/*
 * 主函数
 * 参数：无
 * 返回值：程序执行成功返回0
 */
int main()
{
    // 将浮点数65.5转换为整数后，取其模10的结果
	int f = (int) 65.5 % 10;
	
    // 打印f的值
	printf("%d",f);	

	return 0;
} 
