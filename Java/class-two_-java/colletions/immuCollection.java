package gcp.Collection.colletions;

import java.util.List;
import java.util.Map;
import java.util.Set;

public class immuCollection {
    public static void main(String[] args) {
        //final list
        List<String> imList = List.of("zhangsan","lisi","wangwu");
        //System.out.println(imList);
        //imList.add("1123");
        //imList.remove("zhangsan");

        //final set
        Set<String> imset = Set.of("zhangsan","lisi");
        //System.out.println(imset);
        //imset.add("wangwu");

        //final map
        Map<String, String> immap = Map.of("zhangsan",
                "nanjing","lisi","beijing");
        //System.out.println(immap);
        Set<String> stringSet = immap.keySet();

    }
}
