package pcg.BLL;

public class CostRebate implements Strategy{
    private double moneyRebate = 1d;
    public CostRebate(double moneyRebate) {
        this.moneyRebate = moneyRebate;
        System.out.println("rebate: " + moneyRebate);
    }
    @Override
    public double getCost(double price, int qty) {
         System.out.println("cost: " + price * qty * this.moneyRebate);
        return price * qty * moneyRebate;

    }
}
