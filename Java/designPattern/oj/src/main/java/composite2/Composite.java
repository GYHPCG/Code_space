package composite2;

import java.util.ArrayList;
import java.util.List;

public class Composite extends Component{
    private List<Component>list1 = new ArrayList<>();
    public Composite(String s) {
        super(s);
    }
    public void addComponent(Component c){
        list1.add(c);
    }
    @Override
    public double computerPrice() {
        double total = 0;
        for (Component component : list1) {
            total += component.computerPrice();
        }
        return total;
    }
}
