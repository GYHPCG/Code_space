package hello;

import java.util.Scanner;

public class array2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Scanner in = new Scanner(System.in);
//		int x = in.nextInt();
		int [] numbers = new int[10];
	    numbers[0] = 16;
	    
	    for (int i = 0; i < numbers.length;i++) {
	    	System.out.print(numbers[i]+" ");
	    }
	    int [] b = numbers;
//	    �����������Ͷ���֮�⣬java֮�еĶ���������
	    b[0] = 1;
	    System.out.print("\n");
	    System.out.println(b.length);
	    System.out.println(numbers[0]);
	}

}
