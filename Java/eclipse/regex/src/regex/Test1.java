package regex;

import java.util.Scanner;

public class Test1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();
		in.close();
		//�ж��ǵ绰����
		//System.out.println(s.matches("[1]\\d{10}"));
		
		//�ж�����
		//2986779260@qq.com
		String regex1 = "\\d+[@]{1}[\\w&&[^_]]{2,3}\\.[a-z]{2,3}";
		System.out.println(s.matches(regex1));
		
		

	}

}
