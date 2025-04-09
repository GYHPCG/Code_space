package pcg.BLL;

public class CashFractory {
    private  Strategy st;

    public CashFractory(int cashType) {

        switch (cashType) {
            case 1 -> st = new CostNormal();
            case 2 -> st = new CostRebate(0.8d); //打8折
            case 3 -> st = new CashRebate(200, 50); //满200减50
            default -> System.out.println("超市没有此类活动");
        }
    }

    public double getResult(double price, int qty) {
        return st.getCost(price, qty);
    }

}
