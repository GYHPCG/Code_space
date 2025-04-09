package gcp.homeWork.test2;

public class Test {
    public static void main(String[] args) {
        Triangel triangel = new Triangel(3,4,5);
        triangel.setOffset(5);
        double area = OperationShape.getArea(triangel);
        System.out.println("Triangle's area is : "+area);
    }
}
