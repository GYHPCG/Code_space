package gcp.homeWork.test3.test311;

public class FormatOutput {
    private String s;
    private double Area;
    private double perimeter;

    public FormatOutput() {
    }

    public FormatOutput(String s, double Area, double perimeter) {
        this.s = s;
        this.Area = Area;
        this.perimeter = perimeter;
    }
    public String getOutputValue(){
        //System.out.printf("%s面积为:%.2f,周长为:%.2f\n",s,Area,perimeter);
//        DecimalFormat df = new DecimalFormat("0.00");
//        String sk = s + "面积为:"+df.format(Area) + ",周长为:"+df.format(perimeter) + "\n";
        String sk = s + "面积为:"+String.format("%.2f",Area) + ",周长为:"+String.format("%.2f\n",perimeter);
        return sk;
    }

    /**
     * 获取
     * @return s
     */
    public String getS() {
        return s;
    }

    /**
     * 设置
     * @param s
     */
    public void setShapeType(String s) {
        this.s = s;
    }

    /**
     * 获取
     * @return Area
     */
    public double getArea() {
        return Area;
    }

    /**
     * 设置
     * @param Area
     */
    public void setArea(double Area) {
        this.Area = Area;
    }

    /**
     * 获取
     * @return perimeter
     */
    public double getPerimeter() {
        return perimeter;
    }

    /**
     * 设置
     * @param perimeter
     */
    public void setPerimeter(double perimeter) {
        this.perimeter = perimeter;
    }

    public String toString() {
        return "FormatOutput{s = " + s + ", Area = " + Area + ", perimeter = " + perimeter + "}";
    }
}
