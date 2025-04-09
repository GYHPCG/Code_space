package component;

public class Main {
    public static void main(String[] args) {
        ShapeFactory factory = new ShapeFactory();

       // 创建单独的图形
        System.out.println("单独图形:");
        Shape circle = factory.getShape("圆形");
        Shape rectangle = factory.getShape("矩形");
        circle.draw();
        rectangle.draw();
        System.out.println("\n");
       // 创建文本和图像
        System.out.println("创建文字和图像:");
        Text text = new Text("Hello World");
        Image image = new Image("/oj/asserts/image.png");
        text.draw();
        image.draw();
        System.out.println("\n");
       // 使用组合
        System.out.println("组合图形：");
        CompositeShape composite = new CompositeShape();
        composite.add(circle);
        composite.add(rectangle);
        composite.add(text);
        composite.add(image);
        // 绘制组合图形
        composite.draw();

    }
}
