package gcp.homeWork.test3.test311;

public class Triangle extends Shape{
    private double c1;
    private double c2;
    private double c3;

    public Triangle() {
    }

    public Triangle(double c1, double c2, double c3) {
        this.c1 = c1;
        this.c2 = c2;
        this.c3 = c3;
    }

    @Override
    public double getArea() {
        double p = (c1+c2+c3) / 2;
        double area = Math.sqrt(p*(p-c1)*(p-c2)*(p-c3));
        return area + offset;
    }

    @Override
    public double getPerimeter() {
        return c1 + c2 +c3 + offset;
    }

    /**
     * 获取
     * @return c1
     */
    public double getC1() {
        return c1;
    }

    /**
     * 设置
     * @param c1
     */
    public void setC1(double c1) {
        this.c1 = c1;
    }

    /**
     * 获取
     * @return c2
     */
    public double getC2() {
        return c2;
    }

    /**
     * 设置
     * @param c2
     */
    public void setC2(double c2) {
        this.c2 = c2;
    }

    /**
     * 获取
     * @return c3
     */
    public double getC3() {
        return c3;
    }

    /**
     * 设置
     * @param c3
     */
    public void setC3(double c3) {
        this.c3 = c3;
    }

    public String toString() {
        return "Triangle{c1 = " + c1 + ", c2 = " + c2 + ", c3 = " + c3 + "}";
    }
}
