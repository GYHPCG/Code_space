package gcp.Collection.IDEA.src.gcp.demo1;

import gcp.demo1.Person;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class Test1 {
    public static void main(String[] args) {

        //System.out.println("hello,world12334");
//        //Scanne
        Collection coll  = new ArrayList();
        coll.add(123);
        coll.add("hello");
        coll.add(90);
        coll.add(new String("Tom"));
        coll.add(new Person());
//        System.out.println(coll.size());
//        System.out.println(coll.contains(new String("Tom")));
//        System.out.println(coll.contains(new Person("jerry",20)));
//        System.out.println(coll.contains(123));

        Iterator i = coll.iterator();
        int size = coll.size();
//        coll.size()
//        coll.size();
       // int size1 = coll.size();
        //Iterator iterator = coll.iterator();/
        while(i.hasNext()) {
            System.out.println(i.next());
        }
    }


}
