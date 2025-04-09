package gcp.Collection.myset;

import java.util.TreeSet;

public class myTree {
    public static void main(String[] args) {
        TreeSet<Student> st = new TreeSet<>();
        Student s1 = new Student("zhansan",12);
        Student s2 = new Student("lisi",12);
        Student s3 = new Student("wangwu",24);
        st.add(s1);
        st.add(s2);
        st.add(s3);
        System.out.println(st);
    }
}
