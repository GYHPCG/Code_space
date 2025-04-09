package gcp.myFile;

import java.io.File;

public class demo1 {
    public static void main(String[] args) {
        //直接创建一个File,构造方法1，根据字符串表示的路径
        String str = "D:\\Desktop\\file.txt";
        File file1 = new File(str);
        System.out.println(file1);

        //根据父级路径和子级路径来创建File对象
        String parent = "D:\\Desktop";
        String child = "file.txt";
        File file2 = new File(parent, child);
        System.out.println(file2);

        //根据父级路径和Stirng 表示的子级路径创建File

        File file3 = new File(parent);
        File file4 = new File(file3,child);
        System.out.println(file4);


    }

}
