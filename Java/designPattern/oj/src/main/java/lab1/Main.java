package lab1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String cardNumber = sc.next();
        double amount = sc.nextInt();
        Paymen pay = new Paymen();
        pay.pay(cardNumber, amount);

    }
}
