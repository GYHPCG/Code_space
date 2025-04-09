package lab1;

public class BankContext {
    private Bank bank;
    public BankContext(int bankType) {
        switch (bankType) {
            case 1:
                bank = new ABC();
                break;
            case 2:
                bank = new CCB();
                break;
            case 3:
                bank = new ICBC();
        }
    }

    public void payMoney(double amount) {
        bank.payMoney(amount);
    }
}
