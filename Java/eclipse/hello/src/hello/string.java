package hello;

public class string {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s1 = "abc";
		String s2 = "abc";
//		�ַ���פ����ʹ��s1 and s2 ָ��ͬһ��address�е�object;
//		but for heap, it is not in the same address,because new in two address.
//		if you want to compare two new's object's content,you should use s1.equals(s2).
		String s3 = new String("abc");
		String s4 = new String("abcd");
		System.out.println("s1.address:"+Integer.toHexString(System.identityHashCode(s1)));
		System.out.println("s2.address:"+Integer.toHexString(System.identityHashCode(s2)));
		System.out.println("s3.address:"+Integer.toHexString(System.identityHashCode(s3)));
		System.out.println("s4.address:"+Integer.toHexString(System.identityHashCode(s4)));
		System.out.println("s1==s2: "+(s1==s2));
		System.out.println("s1==s3: "+(s1==s3));
		System.out.println("s2==s4: "+(s2==s4));
//		compare two string's big
		System.out.println("s1==s4: "+s1.compareTo(s4));
//		visit a string's element
		System.out.println(s1.charAt(0));
		
//		find substring,[);����
		System.out.println(s1.substring(1,2));
		System.out.println("***************");
		String s5 = "  adbajcb123356  ";
		System.out.println(s5.indexOf("ajc",2));
		System.out.println(s5.startsWith("ad"));
//		�����в��������ܸı��Լ���ͨ���Ѹı�����ø���һ���µĶ���
		String s6  = s5.trim();
		System.out.println(s6.startsWith("ad"));
		return ;
	}
}
