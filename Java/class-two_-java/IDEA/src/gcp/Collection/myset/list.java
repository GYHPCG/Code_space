package gcp.Collection.myset;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class list {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(9);
//        Integer k = 9;
//        list.remove(9);
//        Iterator<Integer> it = list.iterator();
        //迭代器可以用来删除，但不能添加
//        while(it.hasNext()) {
//            Integer k = it.next();
//            if (k == 2) {
//                it.remove();
//                //list.add(8);
//            }
//            //System.out.println(k);
//        }
        //列表迭代器可以用来往里添加元素
        ListIterator<Integer> it1 = list.listIterator();
        while(it1.hasNext()) {
            Integer l = it1.next();
            if (l == 3 ) it1.add(8);
            System.out.println(l);
        }
        while(it1.hasPrevious()) {
            System.out.println(it1.previous());
        }
        System.out.println(list);
        System.out.println("hello");
    }
}
