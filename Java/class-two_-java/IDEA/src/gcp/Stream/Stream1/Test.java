package gcp.Stream.Stream1;

import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        ArrayList<String> list1  = new ArrayList<>();
        list1.add("张三");
        list1.add("李华");
        list1.add("张无忌");
        list1.add("张华强");
        list1.add("李二");

        //stream获取以张开头长度为3的string
        /*filter()起到过滤作用*/
        list1.stream().filter(name -> name.startsWith("张")).filter(name -> name.length() == 3).forEach(name-> System.out.println(name));
    }
}
