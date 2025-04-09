package hello;

import java.util.Scanner;

public class Method {
//ÇóºÍ
	public static int Getsum(int i, int j) {
		int res = 0;
		for (int k = i; k <= j; k++) {
			res += k;
		}
		return res;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int start = in.nextInt();
		int end = in.nextInt();
		in.close();
		int sum1 = Getsum(start, end);
		System.out.println(sum1);
		

	}

}
