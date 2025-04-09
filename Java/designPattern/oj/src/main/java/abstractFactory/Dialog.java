package abstractFactory;

public class Dialog {
    AbstractFactory factory;

    Button button;

    TextBox textBox;

    public void setFactory(AbstractFactory factory) {

        this.factory = factory;

    }

    public void init(){

        button=factory.createButton();

        textBox=factory.createTextBox();

    }
}
