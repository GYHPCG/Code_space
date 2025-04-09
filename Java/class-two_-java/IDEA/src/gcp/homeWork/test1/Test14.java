package gcp.homeWork.test1;

import java.util.Scanner;

public class Test14 {
    /*public  static boolean com(String s) {
        for (int k = 0, j = s.length() - 1; k <= j; ++k,--j) {
            if (s.charAt(k) != s.charAt(j)) return false;
        }
        return true;
    }*/
    public static int count(int n1,int n2) {
        int count = 0;
        //String s;
        for (int i = n1; i <= n2; ++i) {
            //s = Integer.toString(i);
           //if (com(s)) ++count;
            int j = i, y = 0;
            while (j > 0) {
                y=y*10+j%10;
                j=j/10;
            }
            if (y == i) ++count;
        }
        return count;
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n1 = input.nextInt();

        int n2 = input.nextInt();

        System.out.println(count(n1,n2));

    }
}
