package composite2;

public class Part extends Component{
    private double price;
    public Part(double price, String s) {
        super(s);
        this.price = price;
    }

    @Override
    public double computerPrice() {
        return this.price;
    }
}
