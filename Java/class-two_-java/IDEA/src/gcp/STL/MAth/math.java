package gcp.STL.MAth;

import java.util.HashSet;
import java.util.Iterator;

public class math {
    public static void main(String[] args) {
        //random()
        HashSet<Integer> hs = new HashSet<>();
        //int k =(int) (Math.random()*100 + 1);
        //int size = hs.size();
        //int  i =0;
        //输出1~100的不同的100个随机数
        while (hs.size() <= 98) {
           Integer k =(int) (Math.random()*100 + 1);
            hs.add(k);
            //++i;
        }
        Iterator<Integer> iterator = hs.iterator();
        int count = 0;
        while(iterator.hasNext()) {
            System.out.print(iterator.next()+" ");
            ++count;
        }
        System.out.println();
        System.out.println(count);
        //System.out.println(Math.tan(Math.PI) / 2);
    }
}
