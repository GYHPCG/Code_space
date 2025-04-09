package gcp.homeWork.test1;

import java.util.Scanner;
/*
* 小明要打车去x公里以外，出租车起步价8元，3公里后每公里加2元，10
* 公里后每公里还需要加长途费2元，但总价满60元以后打八五折。小明觉
* 得也许他可以3公里3公里换乘接力（假设每次都能打到车），但是他不
* 太清楚这到底是省钱还是更费钱。请你帮他算一算两种方法各自要花多
* 少钱（费用最后取整，中间计算过程不取整）
* */
public class Test12 {
    public static int oneTaxi(int x){
        int cost = 8;
        if (x > 3 && x <= 10) cost += (x-3) * 2;
        if (x > 10) cost += 7 * 2 + (x-10)*4;
        if (cost >= 60) {
            cost =(int) (cost * 0.85);
        }
        return  cost;
    }
    public static int moreTaxi(int x){
        int t = x / 3;
        if (x % 3 != 0) ++t;
        return 8*t;
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int x = input.nextInt();



        System.out.println(oneTaxi(x));

        System.out.println(moreTaxi(x));

    }
}
