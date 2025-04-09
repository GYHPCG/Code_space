package lab1;

public class ICBC extends Bank{
    @Override
    public void payMoney(double amount) {
        System.out.println("中国工商银行支付 " + amount + " 元");
    }
}
