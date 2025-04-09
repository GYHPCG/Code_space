package gcp.STL.string;

public class char1 {
    public static void main(String[] args) {
        char x = 'a';
        char y = 'b';
        System.out.println(++x);//b
        System.out.println(++y);//c
        System.out.println(x - y);//-1
        Character c1 = 'b';
        Character.isDigit(c1);
        String s = "abcd";
        String k = "av";
        String ks = k.concat(s);
        System.out.println(ks);
        s.toUpperCase();
        System.out.println(s);
        System.out.println( "\\\"hello,world\"");

    }
}
