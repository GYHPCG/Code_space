package gcp.Stream.Stream2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Stream;

public class middleFun {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        ArrayList<String> list1 = new ArrayList<>();
        Collections.addAll(list,"张无忌",
                "周芷若","赵敏","张强","张三丰","张良"
        ,"王二麻子","谢广坤","张无忌","张良");
        Collections.addAll(list1,"Jason","Miku");
        /*filter,起过滤作用，以张开头的人*/
        list.stream().filter(name->name.startsWith("张")).forEach(
                s -> System.out.println(s)
        );
        /*limit,获取前几个元素
        * skip,跳过前几个元素*/
        System.out.println("=====");
        //获取前三个
        list.stream().limit(3).forEach(s-> System.out.println(s));
        //跳过前3个
        list.stream().skip(3).forEach(s-> System.out.println(s));

        /*distinct,去重*/
        /*concat,合并两个流*/
        System.out.println("=======");
        list.stream().distinct().forEach(s-> System.out.println(s));

        System.out.println("========");
        Stream.concat(list.stream(),list1.stream()).forEach(s-> System.out.println(s));

        //map，类型转换，类似于把原来的内容删掉一部分，变为其他
        ArrayList<String> list2 = new ArrayList<>();
        Collections.addAll(list2,"张无忌-90",
                "周芷若-78","赵敏-12","张强-78","张三丰-56","张良-56"
                ,"王二麻子-23","谢广坤-45","张无忌-16","张良-28");
        //提取里面的数字输出
        list2.stream().map(s->Integer.parseInt(s.split("-")[1])).forEach(s->System.out.println(s));
    }
}
