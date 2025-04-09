package day1;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		
//		Animal s = new Animal() {
//
//			@Override
//			public void show() {
//				// TODO Auto-generated method stub
//				System.out.println("÷ÿ–¥show∑Ω∑®");
//			}
//			
//		};
//		method(s);
//		Animal dog = new Dog();
//		SpeakEnglish dog1 = new Dog();
//		dog.show();
//		dog1.speak();
		Dog d1 = new Dog("zhangsan",123);
		String s1 = d1.toString();
		System.out.println(s1);
		
	}
	public static void method(Animal a) {
//		System.out.println();
		a.show();
	}

}
