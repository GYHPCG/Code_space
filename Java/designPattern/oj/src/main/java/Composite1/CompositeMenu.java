package Composite1;

import java.util.ArrayList;
import java.util.List;

public class CompositeMenu extends MenuComponent {
    private List<MenuComponent> list1 = new ArrayList<MenuComponent>();

    public CompositeMenu(String s) {
        super(s);
    }
    public void addComponent(MenuComponent c){
        list1.add(c);
    }
    @Override
    public void print() {
        System.out.println(super.getDes());
        for (MenuComponent component : list1) {
            component.print();
        }
    }
}
