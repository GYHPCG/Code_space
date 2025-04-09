package gcp.method;

//声明一个泛型类
//这里不能设计为static函数，因为调用时必须创建一个类型
class myCom <T extends  Comparable<T> >{
    public  T getMax(T x, T y) {
        return x.compareTo(y) > 0? x:y;
    }

}


//声明一个泛型函数

class myCompare {
    public static < T extends Comparable<T> > T getMax(T x, T y) {
        return x.compareTo(y) > 0? x:y;
    }
}
public class overLoad {
    public static void main(String[] args) {

        myCom<Integer> In = new myCom<>();
        Integer max = In.getMax(2, 5);
        System.out.println(max);

        int res = myCompare.getMax(2,5);
        String s1 = myCompare.getMax("China","Chniese");
        double r = myCompare.getMax(3.4,6.7);
        System.out.println(res);
        System.out.println(s1);
        System.out.println(r);
    }
}
