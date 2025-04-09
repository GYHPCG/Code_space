package date;

import java.util.Scanner;

public class Test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		sc.close();
		int i = Integer.parseInt(line);
		System.out.println(i);
		Integer i1 = 3;
		Integer i3 = 4;

		i1 += i3;
		System.out.println(i1);

	}

}
