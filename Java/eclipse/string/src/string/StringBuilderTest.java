package string;

import java.util.StringJoiner;

public class StringBuilderTest {
	
	public String arrToString(int []arr) {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for (int i = 0; i < arr.length; i++) {
			if (i == arr.length - 1) {
				sb.append(arr[i]);
			}
			else {
				sb.append(arr[i]).append(", ");
			}
			
		}
		sb.append("]");
		return sb.toString();
	}

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {1,2,3};
//		StringBuilderTest s1 = new StringBuilderTest();
//		String s = s1.arrToString(arr);
//		System.out.println(s);
		//jdk8之后才出现的
		StringJoiner sj = new StringJoiner(", ","[","]");
		for (int i = 0; i < arr.length; i++) {
			sj.add(arr[i] + "");
		}
		System.out.println(sj);

	}
	
	

}
