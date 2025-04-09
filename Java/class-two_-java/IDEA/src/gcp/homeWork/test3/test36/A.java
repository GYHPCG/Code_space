package gcp.homeWork.test3.test36;

public class A {
    private A(){};
    private static A a = new A();
    public static A getInstance() {
        return a;
    }

}
