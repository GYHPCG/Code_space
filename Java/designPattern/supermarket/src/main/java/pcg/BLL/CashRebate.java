package pcg.BLL;

public class CashRebate implements Strategy {
    private double moneyCondition = 0d;
    private double moneyReturn = 0d;

    public CashRebate(double moneyCondition, double moneyReturn) {
        this.moneyCondition = moneyCondition;
        this.moneyReturn = moneyReturn;
    }

    @Override
    public double getCost(double price, int qty) {
        double total = price * qty;

        if (total >= moneyCondition && moneyReturn > 0) {

            total -= Math.floor(total / moneyCondition) * moneyReturn;
        }

        return total;
    }
}
