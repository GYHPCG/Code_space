package gcp.myFile;

import java.io.File;

public class demo2 {
    public static void main(String[] args) {
        File f1 = new File("D:\\Desktop\\file.txt");
        System.out.println(f1.isDirectory());
        System.out.println(f1.isFile());
        System.out.println(f1.length());
        System.out.println(f1.exists());
        System.out.println(f1.getAbsolutePath());

        File f2 = new File("D:\\Desktop");
        File[] files = f2.listFiles();
        for (File file: files) {
            System.out.println(file);
        }
    }
}
