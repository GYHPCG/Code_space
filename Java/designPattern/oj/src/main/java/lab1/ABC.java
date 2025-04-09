package lab1;

public class ABC extends Bank{
    @Override
    public void payMoney(double amount) {

        System.out.println("中国农业银行支付 " + amount + " 元");
    }
}
