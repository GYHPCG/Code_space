package hello;

import java.util.Scanner;

public class array1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int x = in.nextInt();
		int [] numbers = new int[100];
		int cnt = 0;
		double sum = 0;
		while (x != -1) {
			numbers[cnt] = x;
			sum += x;
			cnt++;
			x = in.nextInt();
		}
		double average =sum /cnt;
		System.out.println(average);
//		System.out.print("\n");
		if (cnt > 0) {
			
			for (int i = 0; i < cnt; i++) {
				if (numbers[i] > average) {
					System.out.print(numbers[i]+" ");
				}
			}
		}
		System.out.print("\n");
		System.out.println(average);
	}

}
