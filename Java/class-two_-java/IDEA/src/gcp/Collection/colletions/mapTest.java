package gcp.Collection.colletions;

import java.util.*;

public class mapTest {
    public static void main(String[] args) {
        /*输出省份 == 多个该省的城市 */
        //list存放多个城市
        ArrayList<String> city1 = new ArrayList<>();
        Collections.addAll(city1,"南京","无锡","嘉兴","连云港");

        ArrayList<String> city2 = new ArrayList<>();
        Collections.addAll(city2,"合肥","黄山","鞍山");

        ArrayList<String> city3 = new ArrayList<>();
        Collections.addAll(city3,"武汉","孝感","宜昌","汉口");

        HashMap<String,ArrayList<String> > pro = new HashMap<>();
        //添加
        pro.put("江苏",city1);
        pro.put("安徽",city2);
        pro.put("湖北",city3);


        //遍历
        Set<Map.Entry<String, ArrayList<String>>> entries = pro.entrySet();
        for (Map.Entry<String, ArrayList<String>> entry : entries) {
            String key = entry.getKey();
            ArrayList<String> value = entry.getValue();
            StringJoiner sj = new StringJoiner(", ","","");
            for (String s : value) {
                sj.add(s);
            }
            System.out.println(key + " = " + sj);
        }


    }
}
