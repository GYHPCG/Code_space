package sample.BLL;

public class CashRebate implements CashSuper {
    private double moneyRebate=0.8;

    public double getMoneyRebate() {
        return moneyRebate;
    }

    public void setMoneyRebate(double moneyRebate) {
        this.moneyRebate = moneyRebate;
    }

    @Override
    public double acceptCash(Sale sale) {
        CashNormal cashNormal=new CashNormal();
        double total= cashNormal.acceptCash(sale);
        return total*moneyRebate;
    }
}
