package gcp.leetcode;

public class IntegerPartion {

    // 查询划分次数
//    static int countPartion(int n, int m) {
//        if (n ==1 || m == 1)
//            return 1;
//        else if (m > n)
//            return countPartion(n, n);
//        else if (m ==n )
//            return 1 + countPartion(n, n-1);
//        else if (m < n)
//            return countPartion(n-m, m) + countPartion(n, m-1);
//        return 0;
//    }

    // 输出具体划分
    static void countOutput(int n, int m, String str) {
        if (n == 0) // 递归跳出条件1
            System.out.println(str);
        else {
            if (m > 1) // 递归跳出条件2
                countOutput(n, m-1, str);
            if (m <= n) // 因为递归时可能出现 m>n 的情况
                countOutput(n-m, m, m + " " + str);
        }
    }

    public static void main(String[] args) {
        int m = 5;
        int n = 5;
        //System.out.println(countPartion(m, n));
        countOutput(m, n, "");
    }
}
