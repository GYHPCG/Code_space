package hello;

import java.util.Scanner;

public class count {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		int amount = 0;
//		while (number > 0) {
//			amount++;
//			number /= 10;
//		}
		for (int i = 0; i <= number; i++ ) {
			amount += i;
		}
		System.out.println(amount);

	}

}
