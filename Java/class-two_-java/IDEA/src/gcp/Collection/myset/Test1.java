package gcp.Collection.myset;

import java.util.HashSet;

public class Test1 {
    public static void main(String[] args) {
        Student p1 = new Student("zh",20);
        Student p2 = new Student("zh",20);
        //没有重载hashcode时，不同对象的哈希值不同
//        System.out.println(p1.hashCode());//121447
//        System.out.println(p2.hashCode());//121447
//        //哈希碰撞
//        System.out.println("abc".hashCode());
//        System.out.println("acD".hashCode());
        Student p3 = new Student("lisi",34);
        Student p4 = new Student("wangwu",34);
        HashSet<Student> hs = new HashSet<>();
        System.out.println(hs.add(p1));
        System.out.println(hs.add(p2));
        System.out.println(hs.add(p3));
        System.out.println(hs.add(p4));
        System.out.println(hs);
    }
}
