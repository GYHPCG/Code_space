package gcp.homeWork.test3.test311;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {



        // a,b,c用于存储三角形的三条边

        double a, b, c;

        // length,width用于存储长方形的长和宽

        double length, width;

        // area,perimeter用于存储面积和周长

        double area, perimeter;



        // 获取三角形的三条边

        Scanner reader = new Scanner(System.in);

        a = reader.nextDouble();

        b = reader.nextDouble();

        c = reader.nextDouble();



        // 获取长方形的长和宽

        length = reader.nextDouble();

        width = reader.nextDouble();



        // 求三角形的面积和周长

        Shape shape = new Triangle(a, b, c);

        area = ShapeOperation.getAreaOperation(shape);

        perimeter = ShapeOperation.getPerimeterOperation(shape);

        // 格式化输出，保留小数点后2位数据

        FormatOutput formatOutput = new FormatOutput("三角形", area, perimeter);

        System.out.printf(formatOutput.getOutputValue());



        // 求长方形的面积和周长

        shape = new Rectangle(length, width);

        area = ShapeOperation.getAreaOperation(shape);

        perimeter = ShapeOperation.getPerimeterOperation(shape);

        formatOutput.setShapeType("长方形");

        formatOutput.setArea(area);

        formatOutput.setPerimeter(perimeter);

        System.out.printf(formatOutput.getOutputValue());

    }
}
