package day1;

public class Dog extends Animal implements SpeakEnglish{
	private String name;
	private int age;
	
	public Dog() {
		
	}
	public Dog(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}

	@Override
	public void speak() {
		// TODO Auto-generated method stub
		System.out.println("dog is speaking");
		
	}

	@Override
	public void show() {
		// TODO Auto-generated method stub
		System.out.println("dog show");
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return name + ", " + age;
	}
	
	
}
