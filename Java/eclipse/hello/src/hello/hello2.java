package hello;

import java.util.Scanner;

public class hello2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(Math.abs(3-2.0)<1e-6);
		int foot = 0;
		double inch = 0;
		Scanner in = new Scanner(System.in);
		foot = in.nextInt();
		inch = in.nextDouble();
		System.out.println("foot="+foot+",inch="+inch);
		System.out.println((foot + inch / 12)*0.3048);
	}

}
