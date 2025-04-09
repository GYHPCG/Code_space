package component;

public class Image implements Shape{
    private String imagePath;

    // Constructor
    public Image(String imagePath) {
        this.imagePath = imagePath;
    }

    @Override
    public void draw() {
        System.out.println("图像的路径为：" + imagePath);
    }

    @Override
    public void move(int left, int up, int right, int down) {
        System.out.println("移动：" + " 往左：" + left +
                " 往上：" + up + " 向右：" + right + " 向下：" + down);
    }
}
