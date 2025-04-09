package decorator1;

public class ScrollDecorator extends Decorator{
    private Component com;
    public ScrollDecorator(Component com) {
        this.com = com;
    }

    @Override
    void draw() {
        com.draw();
        System.out.print(" ");
        System.out.print("drawScroll");
    }
}
