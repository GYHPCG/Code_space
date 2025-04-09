package regex;

public class Text5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "小史诗qdafaccsdf232小老虎jdfbbjksabfjk890小熊猫";
		//正则替换
		String r1 = "[\\w&&[^_]]+";
		String res = s.replaceAll(r1, "VS");
		System.out.println(res);
		
		//字符串分割
		String[] res1 = s.split(r1);
		for (int i= 0; i < res1.length; i++) {
			System.out.println(res1[i]);
		}
	}

}
