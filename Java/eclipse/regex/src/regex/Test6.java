package regex;

public class Test6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 铺获分组，以左括号作为分组符
		// 目的为取出来重新用
		// \\n表示取第N组再次使用
//		String r1 = "(.).+\\1";
//		System.out.println("a123a".matches(r1));// true
//		System.out.println("a123b".matches(r1));// false

//		String r2 = "((.)\\2*).+\\1";
//		System.out.println("aaaaa123a".matches(r2));// true
//		System.out.println("a123a".matches(r2));// false

		String s = "我要学学编编编编程程程程程程";
		String res = s.replaceAll("(.)\\1+", "$1");
		// 在正则表达式中，取组用\\号，而在正则外面，用$;
		System.out.println(res);

		// 非捕获分组

		String s1 = "522622200108120030";
		String res1 = "[1-9]\\d{16}(?:\\d|X|x)\\1";
		String resu = s1.replaceAll(res1, "vs");
		System.out.println(resu);
	}

}
