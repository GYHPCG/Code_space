package gcp.homeWork.test2;

public class Parallell extends Shape{
    private int x;
    private int y;

    public Parallell() {
    }

    public Parallell(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double getArea() {
        return x*y + offset;
    }

    @Override
    public int getPre() {
        return 2*(x+y) + offset;
    }

    /**
     * 获取
     * @return x
     */
    public int getX() {
        return x;
    }

    /**
     * 设置
     * @param x
     */
    public void setX(int x) {
        this.x = x;
    }

    /**
     * 获取
     * @return y
     */
    public int getY() {
        return y;
    }

    /**
     * 设置
     * @param y
     */
    public void setY(int y) {
        this.y = y;
    }

    public String toString() {
        return "Parallell{x = " + x + ", y = " + y + "}";
    }
}
