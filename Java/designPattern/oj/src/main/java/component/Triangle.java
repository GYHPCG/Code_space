package component;

public class Triangle implements Shape{
    @Override
    public void draw() {
        System.out.println("画出三角形");
    }

    @Override
    public void move(int left, int up, int right, int down) {
        System.out.println("移动：" + " 往左：" + left +
                " 往上：" + up + " 向右：" + right + " 向下：" + down);
    }
}
