package gcp.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Find_K_closet658 {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        Integer[] arr1 = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) arr1[i] = arr[i];
        Arrays.sort(arr1,(Integer a, Integer b) -> {
            return Math.abs(a - x);
        });

        List<Integer> A = new ArrayList<>();
        Arrays.sort(arr);
        for(int i = 0; i < k; i++) {
            A.add(arr[i]);
        }
        return A;
    }
    public static void main(String[] args) {
        /*int[] arr= {1,6,4,3,2,5};
        Arrays.sort(arr,(Integer a, Integer b)->{
            return a - b;
        });
        for(int k:arr) System.out.println(k);*/
    }
}
