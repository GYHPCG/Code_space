package vendingmachine;

public class VendingMachine {
	int price = 100;
	int balance;
	int amount;
	//无参构造函数
	public VendingMachine() {
		// TODO Auto-generated constructor stub
	}
	//overriding a value in it
	 VendingMachine(int x) {
		// TODO Auto-generated constructor stub
		 this.balance = x;
	}
	void showPrice() {
		System.out.println(price);
	}
	void ShowAttention() {
		System.out.println("welcome!");
	}
	void getAmount(int amount) {
		this.amount = amount;
	}
	void showBalance() {
		balance = balance + amount;
		balance = amount - price;
		System.out.println(balance);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		VendingMachine vm = new VendingMachine();
		System.out.println(vm);
		vm.ShowAttention();
		vm.getAmount(120);
		vm.showBalance();
		VendingMachine vm1 = new VendingMachine(100);
		vm1.ShowAttention();
		vm1.getAmount(200);
		vm1.showBalance();
	}

}
