package component;

public class ShapeFactory {
    Shape getShape(String shapeType) {
        if (shapeType == null) {
            return null;
        }
        if (shapeType.equals("圆形")) {
            return new Circle();
        } else if (shapeType.equals("矩形")) {
            return new Rectangle();
        } else if (shapeType.equals("三角形")) {
            return new Triangle();
        }
        return null;
    }
}
