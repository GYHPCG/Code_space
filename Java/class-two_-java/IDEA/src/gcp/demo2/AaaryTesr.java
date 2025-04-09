package gcp.demo2;

public class AaaryTesr {
    public static void main(String[] args) {
        MyArraylist<Object> objectMyArraylist = new MyArraylist<>();
        MyArraylist<Integer> arr = new MyArraylist<>();
        arr.add(12);
        arr.add(90);
        arr.add((8));
        Integer integer = arr.get(0);
        System.out.println(integer);
        System.out.println(arr);
    }
}
