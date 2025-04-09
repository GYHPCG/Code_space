package gcp.myFunction.Fun1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

public class Fundemo1 {
    public static void main(String[] args) {
        ArrayList<String> List = new ArrayList<>();
        Collections.addAll(List,"1","2","3","4","5","6");
        //利用方法引用将 List 里面的内容变为 int
        java.util.List<Integer> collect = List.stream().map(Integer::parseInt).collect(Collectors.toList());
        System.out.println(collect);
    }
}
