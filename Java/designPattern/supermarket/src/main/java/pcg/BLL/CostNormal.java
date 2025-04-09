package pcg.BLL;

public class CostNormal implements Strategy{
    @Override
    public double getCost(double price, int qty) {
        return price * qty;
    }
}


