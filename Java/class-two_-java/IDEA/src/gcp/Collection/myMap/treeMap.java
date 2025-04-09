package gcp.Collection.myMap;

import java.util.Comparator;
import java.util.TreeMap;

public class treeMap {
    public static void main(String[] args) {
        TreeMap<studnet,String> tmp = new TreeMap<>(new Comparator<studnet>() {
            @Override
            public int compare(studnet o1, studnet o2) {
                return o2.getAge() - o1.getAge();
            }
        });
        //treemap默认会对key进行排序，因此如果是自定义对象，要写排序规则
        studnet s1 = new studnet("zhangsan",23);
        studnet s2 = new studnet("lisi",25);
        studnet s3 = new studnet("wangwu",24);
        //如果按照排序规则前后添加的一样，那么前面的会被后面的覆盖
        tmp.put(s1,"贵州");
        tmp.put(s2,"云南");
        tmp.put(s3,"湖北");
        //System.out.println(tmp);
        tmp.forEach((studnet studnet, String s) ->{
                System.out.println(studnet.getName()+ " " + studnet.getAge() + s);
            }
        );
    }
}
