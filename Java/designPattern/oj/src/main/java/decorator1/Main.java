package decorator1;

public class Main {

    public static void main(String[] args) {

        Component table = new ScrollDecorator(new BorderDecorator(new Table()));

        Component text = new BorderDecorator(new TextBox());

        table.draw();

        System.out.println();

        text.draw();

    }

}
