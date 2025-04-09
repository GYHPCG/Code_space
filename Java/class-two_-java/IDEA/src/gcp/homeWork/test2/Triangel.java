package gcp.homeWork.test2;

public class Triangel extends Shape {
    private int c1;
    private int c2;
    private int c3;

    public Triangel() {
    }

    public Triangel(int c1, int c2, int c3) {
        this.c1 = c1;
        this.c2 = c2;
        this.c3 = c3;
    }

    public double getArea() {
        double p = (c1+c2+c3) / 2;
        double area = Math.sqrt(p*(p-c1)*(p-c2)*(p-c3));
        return area + offset;
    }

    @Override
    public int getPre() {
        return c1+c2+c3 + offset;
    }

    /**
     * 获取
     * @return c1
     */
    public int getC1() {
        return c1;
    }

    /**
     * 设置
     * @param c1
     */
    public void setC1(int c1) {
        this.c1 = c1;
    }

    /**
     * 获取
     * @return c2
     */
    public int getC2() {
        return c2;
    }

    /**
     * 设置
     * @param c2
     */
    public void setC2(int c2) {
        this.c2 = c2;
    }

    /**
     * 获取
     * @return c3
     */
    public int getC3() {
        return c3;
    }

    /**
     * 设置
     * @param c3
     */
    public void setC3(int c3) {
        this.c3 = c3;
    }

    public String toString() {
        return "Triangel{c1 = " + c1 + ", c2 = " + c2 + ", c3 = " + c3 + "}";
    }
}
