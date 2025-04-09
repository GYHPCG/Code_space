package gcp.demo4;

public class test1 {
    public static void main(String[] args) {
        generic list= new generic();
        list.add("123");
        System.out.println(list);
        generic1<Integer> li  = new generic1<>();
        li.add(9);
        li.add(0);
        li.add(0,12);
        System.out.println(li);
    }
}
