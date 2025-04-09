package abstractFactory;

public class WindowFactory implements AbstractFactory{
    @Override
    public Button createButton() {
        return new WindowButton();
    }

    @Override
    public TextBox createTextBox() {
        return new WindowTextBox();
    }
}
