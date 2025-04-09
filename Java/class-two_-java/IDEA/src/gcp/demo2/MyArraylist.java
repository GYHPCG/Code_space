package gcp.demo2;

import java.util.Arrays;

public class MyArraylist <E>{
    Object[] obj= new Object[10];
    int size;

    public MyArraylist() {
    }
    public  boolean add(E e) {
        obj[size++] = e;
        return true;
       // if (size == 10) return false;
    }
    public E get(int index) {
        return (E)obj[index];
    }

    @Override
    public String toString() {
        return Arrays.toString(obj);
    }
}
