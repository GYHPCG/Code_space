package string;

import java.util.Scanner;

public class RotateString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String s1 = in.next();
		String s2 = in.next();
		in.close();
//		String s3 = rotate(s2);
		boolean judge = check(s1,s2);
		System.out.println(judge);

	}

	private static boolean check(String s1, String s2) {
		// TODO Auto-generated method stub
		for (int i = 0; i < s1.length(); i++) {
			s2 = rotate(s2);
			if (s1.equals(s2)) {
				System.out.println(i);
				return true;
			}
		}
		return false;
	}

	private static String rotate(String s2) {
		// TODO Auto-generated method stub
		//methon1,use the String to do
//		char f = s2.charAt(0);
//		String subs = s2.substring(1);
//		subs = subs + f;
		//methon2,use the array
		char[] s3 = s2.toCharArray();
		char arr1 = s3[0];
		for (int i = 1; i < s3.length; i++) {
			s3[i-1] = s3[i];
		}
		s3[s3.length-1] = arr1;
		String subs = new String(s3);
		return subs;
	}
	

}
