package lab1;

public class Paymen {
    private Bank bank;
    public boolean pay(String cardNumber, double amount) {
        if (!CheckBankCard.checkBankCard(cardNumber)) {
            System.out.println("输入的银行卡无效，请重新输入");
            return false;
        }

        if (cardNumber.startsWith("622280")) {
                bank = new CCB();
        }
        else if (cardNumber.startsWith("621559")) {
                bank = new ICBC();

        }
        else if (cardNumber.startsWith("622848")) {
                bank = new ABC();

        }
        bank.payMoney(amount);

        return true;
    }
}
