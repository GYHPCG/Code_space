package first;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		Fraction a = new Fraction(in.nextInt(), in.nextInt());

		Fraction b = new Fraction(in.nextInt(),in.nextInt());

		a.print();

		b.print();

		a.plus(b).print();

		a.multiply(b).plus(new Fraction(5,6)).print();

		a.print();

		b.print();

		in.close();
	}
}
class Fraction {
	int x;
	int y;
	public Fraction() {
		// TODO Auto-generated constructor stub
		
	}
	public Fraction(int x1, int x2) {
		// TODO Auto-generated constructor stub
		x = x1;
		y = x2;
	}
	void print() {
		for (int i = 2; i <= 7; i++) {
			while ((x%i)==0 && (y%i)==0) {
				x /= i;
				y /= i;
			}
		}
		int z  = x%y;
		if (z == 0) {
			x = 1;
		}
		if (y != 1 && z != 0) {
			System.out.println(x+"/"+y);
		}
		else {
			System.out.println(x);
		}
	}
	Fraction plus(Fraction b) {
		Fraction res = new Fraction();
		int com = y * b.y;
		int x1 = x *b.y;
		int x2 = b.x * y;
		res.x = x1 + x2;
		res.y = com;
		return res;
	}
	Fraction multiply(Fraction b) {
		Fraction res1 = new Fraction();
		res1.x = x * b.x;
		res1.y = y * b.y;
		return res1;
	}
}


