package gcp.leetcode;

import java.util.Arrays;

public class Special_arrears {
    public static void main(String[] args) {
        Integer [] nums = {1,2,3,4,5,6};
        Arrays.sort(nums,(a,b)->{
            return b - a;
        });
        for (int i = 0; i < nums.length; i++) {
            System.out.println(nums[i]);
        }
    }
}
