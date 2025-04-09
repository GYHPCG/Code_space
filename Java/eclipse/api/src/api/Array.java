package api;

import java.util.Arrays;

public class Array {

	public static void main(String[] args) {
		int[] arr = { 5, 6, 3, 10, 9, 7, 8, 1, 2, 4 };
		// copy
		int[] arr1;
		arr1 = Arrays.copyOf(arr, 10);
		// 排序数据
		Arrays.sort(arr);
		System.out.println(Arrays.toString(arr1));
		// 填充数据
//		Arrays.fill(arr, 10);
//		System.out.println(Arrays.toString(arr));
		// 二分查找
		System.out.println(Arrays.binarySearch(arr, 10));
	}

}
