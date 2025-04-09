package component;

public class Text implements Shape{
    private String text;

    // Constructor
    public Text(String text) {
        this.text = text;
    }
    @Override
    public void draw() {
        System.out.println("写出的文本为： " + text);
    }

    @Override
    public void move(int left, int up, int right, int down) {
        System.out.println("移动：" + " 往左：" + left +
                " 往上：" + up + " 向右：" + right + " 向下：" + down);
    }
}
