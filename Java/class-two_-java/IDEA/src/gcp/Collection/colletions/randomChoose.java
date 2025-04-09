package gcp.Collection.colletions;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class randomChoose {
    public static void main(String[] args) {
    /*在10个人中随机抽取一个人*/
        ArrayList<String> arr = new ArrayList<>();
        /*colletions添加内容*/
        Collections.addAll(arr,"张三","李四","王五","迈克",
        "Tom","John","Anger","Lisa","Frank","阿贵");
        /*随机的方法1*/
        /*Random r = new Random();
        int index = r.nextInt(arr.size());
        String s = arr.get(index);
        */
//        System.out.println(s);


        /*随机方法2*/
        Collections.shuffle(arr);
        //System.out.println(arr.get(0));
        /*随机抽取人，百分之七十抽取男生，百分之三十女生*/
        //利用list来获取概论
        ArrayList<Integer> gaiLv = new ArrayList<>();
        //1 is boy and 0 is girl
        Collections.addAll(gaiLv,1,1,1,1,1,1,1,0,0,0);
        Random r = new Random();
        int i = r.nextInt(gaiLv.size());
        int judge = gaiLv.get(i);
        System.out.println(judge);
        /*build two lists, one is boy another is girl*/
        ArrayList<String> boyList = new ArrayList<>();
        Collections.addAll(boyList,"张三","李四","王五","迈克","阿贵");

        ArrayList<String> girlList = new ArrayList<>();
        Collections.addAll(girlList, "Tom","John","Anger","Lisa","Frank");
        if (judge == 1) {
            Random r2 = new Random();
            int i2 = r2.nextInt(boyList.size());
            System.out.println(boyList.get(i2));
        } else {
            Random r3 = new Random();
            int i3 = r3.nextInt(girlList.size());
            System.out.println(girlList.get(i3));
        }

    }
}
