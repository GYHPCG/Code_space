package gcp.Collection.myMap;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class TraveMap {
    public static void main(String[] args) {
        Map<String,String> mp = new HashMap<>();
        mp.put("ABC","abc");
        mp.put("DEF","def");
        mp.put("HIJ","hij");
        //遍历方式1，键找值
        Set<String> strings = mp.keySet();
            //1.1迭代器遍历
           /* Iterator<String> iterator = strings.iterator();
            while(iterator.hasNext()) {
                String k = iterator.next();
                System.out.println(k + " -> "+mp.get(k));
            }*/
 /*           1.2增强for
            for (String string : strings) {
                String s = mp.get(string);//通过获取键来找到值
                System.out.println(string+ " -> "+ s);

            }*/
            //1.3lambda遍历
            //strings.forEach(s-> System.out.println(s+" -> "+ mp.get(s)));
        //遍历方式2，键值对象,
        Set<Map.Entry<String, String>> entries = mp.entrySet();//键值对是一个entry对象
              //2.1增强for
    //        for (Map.Entry<String, String> entry : entries) {
    //            System.out.println(entry.getKey()+" -> "+entry.getValue());
    //        }
            //2.2迭代器
            /*terator<Map.Entry<String, String>> iterator = entries.iterator();
            while(iterator.hasNext()) {
                Map.Entry<String,String> en =  iterator.next();
                //不能用以下方法，这是用迭代器特别要注意的地方
                // k 中的iterator.next()和 v 中的iterator.next()不是同一个，v是k的下一个
               *//* String k = iterator.next().getKey();
                String v = iterator.next().getValue();*//*
                String k = en.getKey();
                String v = en.getValue();
                System.out.println(k+" -> " + v);
            }*/
            //2.3lambda
            //entries.forEach(en-> System.out.println(en.getKey()+"->"+en.getValue()));
        //直接lambad表达式
       /* mp.forEach(new BiConsumer<String, String>() {
            @Override
            public void accept(String key, String value) {
                System.out.println(key+"->"+value);
            }
        });*/
        mp.forEach((key,value)-> System.out.println(key +"->"+value));
    }

}
