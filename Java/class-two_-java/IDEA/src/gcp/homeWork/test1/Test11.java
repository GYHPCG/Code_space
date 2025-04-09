package gcp.homeWork.test1;

import java.util.Scanner;
/*一只准备过冬的松鼠要将一堆松子从森林里搬运回自己的洞，松鼠每次能带n颗松子，但松鼠每走一米
就要吃掉一颗松子（走不到一米则不吃松子）。
已知松子共有x颗，搬运距离有y米，编个程序计算一下松鼠最多能有多少松子留着过冬。
x、y和n通过键盘依次输入，输出剩余的松子数量。*/
/* 3000 1000 1000
    534
* */
public class Test11 {
    public static int remaining(int totalNumber,int distance,int capacity) {
        //int sum = 0;
        /*int nm = totalNumber / capacity;
        if (totalNumber % capacity == 0) nm = nm;
        else nm = nm + 1;
        sum = totalNumber - nm * distance;*/
        int n = 0;
        while (distance > 0 && totalNumber > distance) {
            n = totalNumber / capacity;
            //if (totalNumber % capacity != 0) ++n;
            int m = totalNumber - n * capacity;
            while (n-- != 0) {
                totalNumber -= capacity;
                totalNumber += capacity - 2;
            }
//            if (m != 0) {
//                totalNumber -=
//            }
            --distance;
        }
        if (distance != 0 ) totalNumber = totalNumber - distance;
        return totalNumber;
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int totalNumber = input.nextInt();

        int distance = input.nextInt();

        int capacity = input.nextInt();

        System.out.println(remaining(totalNumber,distance,capacity));

    }
}
