package component;

import java.util.ArrayList;
import java.util.List;

public class CompositeShape implements Shape {
    private List<Shape> shapes = new ArrayList<Shape>();

    public void add(Shape shape) {
        shapes.add(shape);
    }

    @Override
    public void draw() {
        for (Shape shape : shapes) {
            shape.draw();
        }
    }

    @Override
    public void move(int left, int up, int right, int down) {
        System.out.println("移动：" + " 往左：" + left +
                " 往上：" + up + " 向右：" + right + " 向下：" + down);
    }
}
