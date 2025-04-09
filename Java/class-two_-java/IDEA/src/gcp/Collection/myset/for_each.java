package gcp.Collection.myset;

import java.util.ArrayList;
import java.util.Collection;
import java.util.function.Consumer;

public class for_each {
    public static void main(String[] args) {
        Collection<String> coll  = new ArrayList<>();
        coll.add("zhangsan");
        coll.add("lisi");
        coll.add("wangwu");
        for (String s : coll) {
            s = "qq";//注意：增强for里面是无法修改数据内容的
            System.out.println(s);
        }
        //lambda遍历
            //匿名内部类
        System.out.println();
        coll.forEach(new Consumer<String>() {
            @Override
            public void accept(String s) {
                System.out.println(s);
            }
        });
        //
        System.out.println("---------");
        //lambda简化版
        coll.forEach(s->System.out.println(s)
        );
    }
}
