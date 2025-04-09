package gcp.homeWork.test2;

public abstract class Shape {
    protected int offset;
    public abstract double getArea();
    public abstract int getPre();
    void setOffset(int x) {
        offset = x;
    }

}
