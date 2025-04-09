package gcp.leetcode;

public class substr300 {
    public static int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int len = 1;
        int temp = 1;
        for (int i = 0; i < n - 1; i++) {
            temp = 1;
            for (int j = i + 1; j < n;j++) {
                if (nums[j] > nums[i]) {
                    temp++;
                }
                if (temp > len) {
                    len = temp;
                }
            }
            System.out.println("i:"+i+" "+len);
        }
        return len;
    }
    public static void main(String[] args) {
        int[] arr = {10,9,2,5,3,7,101,18};
        int res = lengthOfLIS(arr);
        System.out.println(res);
    }
}
