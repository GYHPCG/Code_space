package sample.BLL;

public class CashReturn implements CashSuper {

    private double condition=300;
    private double returnMoney =50;


    @Override
    public double acceptCash(Sale sale) {
        CashNormal cashNormal=new CashNormal();
        double total= cashNormal.acceptCash(sale);
        if(total>condition){
            return total-returnMoney;
        }
        return total;
    }
}
