package gcp.myFile;

import java.io.File;

public class demo3 {

    public static void main(String[] args) {
        //获取我的个人电脑中所有.txt文件
        findTxt();

    }
    public static void findTxt() {
        //获取盘符
        File[] files = File.listRoots();
        for (File file : files) {
            getTxt(file);
        }
    }
    public static void getTxt(File f) {
        //File file = new File(f);
        File[] files = f.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    if (file.getName().endsWith(".txt")) {
                        System.out.println(file);
                    }
                }
                else {
                    getTxt(file);
                }
            }
        }

    }
}
