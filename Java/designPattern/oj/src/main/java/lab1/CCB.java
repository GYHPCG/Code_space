package lab1;

public class CCB extends Bank{
    @Override
    public void payMoney(double amount) {

        System.out.println("中国建设银行支付 " + amount + " 元");
    }
}
