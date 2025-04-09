package gcp.Stream.Stream1;

import java.util.Arrays;
import java.util.stream.Stream;

public class demo3 {
    public static void main(String[] args) {
        int[] arr1 = {1,2,3,4};
        String[] arr2 = {"a","b","c"};
        Arrays.stream(arr1).forEach(s-> System.out.println(s));
        //stream.of对普通数组无法执行，但是对引用数组可用
        //Stream.of(arr1).forEach(s-> System.out.println(s));
        Stream.of(arr2).forEach(s-> System.out.println(s));
    }
}
