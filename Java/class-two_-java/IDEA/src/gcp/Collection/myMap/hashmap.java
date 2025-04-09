package gcp.Collection.myMap;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class hashmap {
    public static void main(String[] args) {
//        Map<String,String> mp = new HashMap<>();
//        //添加，覆盖
//        mp.put("guojing","huangrong");
//        mp.put("hello","world");
//        mp.put("YangGuo","XiaoLongnv");
//
//        //遍历
//        mp.remove("guojing");
//        System.out.println(mp);
        //添加学生姓名和籍贯
        HashMap<studnet, String> Hasmap =  new HashMap<>();
        studnet s1 = new studnet("zhangsan",34);
        studnet s2 = new studnet("lisi",20);
        studnet s3 = new studnet("wangwu",13);
        studnet s4 = new studnet("lisi",20);
        Hasmap.put(s1,"山东");
        Hasmap.put(s2,"浙江");
        Hasmap.put(s3,"四川");
        Hasmap.put(s4,"贵州");
        //遍历1
        Set<studnet> studnets = Hasmap.keySet();
        for (studnet studnet : studnets) {
            System.out.println(studnet + Hasmap.get(studnet));

        }
        //遍历2
        System.out.println("----------");
        Set<Map.Entry<studnet, String>> entries = Hasmap.entrySet();
        for (Map.Entry<studnet, String> entry : entries) {
            System.out.println(entry.getKey()+entry.getValue());

        }
        //遍历3
        Hasmap.forEach((s,v)-> System.out.println(s+v));


    }
}
