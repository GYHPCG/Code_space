package regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "Java自97年问世以来，目前企业中用得最多的是Java8和Java11,abbbbbbbbbbaaaa"
				+ "下一个长期支持的版本是Java17,相信在未来不久Java17也会登上历史舞台";
		
		//greedy 爬取, Java默认Greedy, 在greedy后面加上？问号就是非贪婪获取
		String regex1 = "ab+?" ;
		Pattern p = Pattern.compile(regex1);
		
		Matcher m = p.matcher(s);
		while(m.find()) {
			
			System.out.println(m.group());
		}
		
		
	}

}
