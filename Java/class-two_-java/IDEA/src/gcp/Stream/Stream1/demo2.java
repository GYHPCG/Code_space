package gcp.Stream.Stream1;

import java.util.HashMap;

public class demo2 {
    public static void main(String[] args) {
        //双列集合，要化解为单列集合
        HashMap<String,Integer> hm = new HashMap<>();
        hm.put("aaa",111);
        hm.put("bbb",222);
        hm.put("ccc",333);
        //方法1
        hm.keySet().stream().forEach(s-> System.out.println(s));
        System.out.println("==============");
        //方法二
        hm.entrySet().stream().forEach(s-> System.out.println(s));
    }
}
