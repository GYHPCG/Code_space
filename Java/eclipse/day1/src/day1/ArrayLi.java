package day1;

import java.util.ArrayList;

public class ArrayLi {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 0; i < 5; i++) {
			list.add(i+3);
		}
//		ÈÝÆ÷£ºÔöÉ¾²é¸Ä
		System.out.println(list);
//		list.remove(3);
		System.out.println(list);
//		list.remove
		int  k = list.get(3);
		System.out.println(k);
		list.set(0, 100);
		System.out.println(list);
		
		
	}

}
