package gcp.homeWork.test1;

import java.util.Scanner;
/*
* 有一家生产玻璃瓶装汽水的饮料厂为了实现环保，
* 他们决定搞一次循环利用瓶子的促销活动。具体方式是：
一瓶汽水售价m（m > 1）元，促销期间把一个完好的空瓶子
* 退回给商家可以换回1元，你有x元钱，如果全部用来买这种
* 汽水可以买y瓶，喝完以后把y个瓶子换回y元钱，又可以买z
* 瓶汽水，喝完又换......直到换回的钱不够买一瓶汽水为止，
* 计算你最多能喝到多少瓶汽水。
*
* */
public class Test13 {
    public static int canDrink(int m,int x){
       int count = 0;
       while (x >= m) {
           x = x - m;
           ++x;
           ++count;
       }
      return count;
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int m = input.nextInt();

        int x = input.nextInt();



        System.out.println(canDrink(m,x));

    }
}
