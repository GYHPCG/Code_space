package Composite1;

public class MenuItem extends MenuComponent{

    public MenuItem(String s) {
        super(s);
    }

    @Override
    public void print() {
        System.out.println(super.getDes());
    }
}
