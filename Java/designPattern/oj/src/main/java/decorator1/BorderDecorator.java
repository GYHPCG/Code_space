package decorator1;

public class BorderDecorator extends Decorator{
    private Component com;
    public BorderDecorator(Component com) {
        this.com = com;
    }

    @Override
    void draw() {
        com.draw();
        System.out.print(" ");
        System.out.print("drawBorder");
    }
}
