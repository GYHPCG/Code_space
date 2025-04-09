package gcp.demo2;

import gcp.demo1.Person;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Test2 {
    public static void main(String[] args) {
        //System.out.println("hello");
        ArrayList list = new ArrayList();
        list.add(123);
        list.add(456);
        list.add(new Person("Tom",24));
        list.add("AA");
        System.out.println(list);

        List list1 = Arrays.asList(1,2,3);
        list.add(list1);
        System.out.println(list);

    }
}
