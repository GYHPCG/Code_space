package gcp.Stream.Stream1;

import java.util.ArrayList;
import java.util.Collections;

public class demo1 {
    public static void main(String[] args) {
        //单列集合，调用collections中的方法
        ArrayList<String> list1  = new ArrayList<>();
        Collections.addAll(list1,"b","c","d","e");
        list1.stream().forEach(s-> System.out.println(s));
    }
}
