package gcp.Collection.myset;

import java.util.Iterator;
import java.util.TreeSet;
import java.util.function.Consumer;

public class myTreeSet {
    public static void main(String[] args) {
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(7);
        ts.add(0);
        ts.add(8);
        ts.add(5);
        ts.add(2);
       // System.out.println(ts);
        //迭代器遍历
        Iterator<Integer> ii = ts.iterator();
        while(ii.hasNext()) {
            System.out.println(ii.next());
        }
        //增强for
        System.out.println("------------");
        for (int i : ts) {
            System.out.println(i);
        }
        //lambda
        System.out.println("---------");
       ts.forEach(new Consumer<Integer>() {
           @Override
           public void accept(Integer integer) {
               System.out.println(integer);
           }
       });
        System.out.println("---------");
        ts.forEach(integer -> System.out.println(integer));
    }
}
