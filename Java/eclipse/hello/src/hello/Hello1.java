package hello;

import java.util.Scanner;

public class Hello1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("hello,world!");
		Scanner in = new Scanner(System.in);
		final int amount = 100;
//		amount = 200;
		int price = in.nextInt();
//		System.out.println(in.nextLine());
		System.out.println(amount+"-"+price+"=" +(amount-price));
	}

}
