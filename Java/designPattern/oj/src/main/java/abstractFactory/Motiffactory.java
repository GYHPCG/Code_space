package abstractFactory;

public class Motiffactory implements AbstractFactory{
    @Override
    public Button createButton() {
        return new MotifButton();
    }

    @Override
    public TextBox createTextBox() {
        return new MotifTextBox();
    }
}
