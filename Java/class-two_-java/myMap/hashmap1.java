package gcp.Collection.myMap;

import java.util.HashMap;
import java.util.Map;

public class hashmap1 {
    public static void main(String[] args) {
        Map<String,String> mp = new HashMap<>();
        //添加，覆盖
        mp.put("guojing","huangrong");
        mp.put("hello","world");
        mp.put("YangGuo","XiaoLongnv");

        //遍历
        System.out.println(mp);
    }
}
