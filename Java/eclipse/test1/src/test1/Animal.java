package test1;

public class Animal {
//	private int
	public void eat() {
		System.out.println("�ǣ�"+ this+" eat");
	}
	public void drink() {
		System.out.println("�ǣ�"+ this+" drink");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cat c = new Cat();
		c.eat();
		c.getMouse();
		Cat1 c1 = new Cat1();
		c1.drink();
		System.out.println();

	}

}
