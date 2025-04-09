package gcp.demo2;

import gcp.demo1.Person;

import java.util.HashSet;

public class setTest1 {
    public static void main(String[] args) {
        HashSet set = new HashSet();
        Person p1 = new Person("AA",24);
        Person p2 = new Person("BB",25);
        set.add(p1);
        set.add(p2);
        p1.setName("CC");
        set.remove(p1);
        System.out.println(set);

    }
}
