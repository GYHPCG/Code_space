package gcp.homeWork.test3.test311;

public abstract class Shape {

    // 求面积

    public abstract double getArea();

    // 求周长

    public abstract double getPerimeter();



    // 偏移值--在面积和周长真实值基础上加上偏移值进行安全处理

    protected double offset;

    public void setOffset(double offset) {

        this.offset = offset;

    }

    public double getOffset() {

        return offset;

    }

}
