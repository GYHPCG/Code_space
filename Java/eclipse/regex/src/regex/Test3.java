package regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "Java自97年问世以来，目前企业中用得最多的是Java8和Java11,"
				+ "下一个长期支持的版本是Java17,相信在未来不久Java17也会登上历史舞台";
		//带条件的爬取
		//爬取版本号为8，11，17的文本，但只要输出Java,不显示版本号。
		String regex1 = "Java(?=8|11|17)";
		//?问号显示前面的数据为Java
		//=等于表示在后面要跟随的数据
		//但是获取结果的时候，只要前面那部分
		
		String regex2 = "Java(?:8|11|17)";
		//：冒号表示要跟后面的部分
		
		String regex3 = "Java(?!8|11|17)";
		//!表示除掉
		Pattern p1 = Pattern.compile(regex3);
		Matcher m1 = p1.matcher(s);
		while(m1.find()) {
			System.out.println(m1.group());
		}
		
	}

}
