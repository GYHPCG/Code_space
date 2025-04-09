package regex;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test2 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//����
		String s = "Java��97�������������һֱ�յ����ǵ��ձ���ڻ�ӭ,Java8��Java11,Java17";
		String refex = "[^(Java\\d{0,2})]";
		Pattern m = Pattern.compile(refex);
		
		Matcher p = m.matcher(s);
		
		while(p.find()) {
			String x = p.group();
			System.out.println(x);
		}
		System.out.println("----------");
		//��������
		String u = "https://www.sengzan.com/jiaoyu/29104.html";
		URL url = new URL(u);
		//��������
		URLConnection conn = url.openConnection();
		
		BufferedReader br  = new BufferedReader(new InputStreamReader(conn.getInputStream()));
		String line;
		String regex = "[1-9]\\d{17}";
		Pattern p1 = Pattern.compile(regex);
		//一行一行读取
		while ((line = br.readLine()) != null) {
//			System.out.println(line);
			Matcher m1 = p1.matcher(line);
			while(m1.find()) {
				System.out.println(m1.group());
			}
		}
		

	}

}
