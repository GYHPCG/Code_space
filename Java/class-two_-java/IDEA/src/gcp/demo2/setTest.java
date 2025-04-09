package gcp.demo2;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class setTest {
    //@Test
    //hashset经常用来去重，过滤
    public  static List dublist(List list) {
        HashSet set = new HashSet();
        set.addAll(list);
        return new ArrayList(set);
    }

   public static void main(String[] args) {
       List list = new ArrayList();
       list.add(123);
       list.add(1);
       list.add(123);
       list.add(4);
       list.add(4);
       list.add(1);
       List list2 = dublist(list);
       System.out.println(list2);
   }




}
