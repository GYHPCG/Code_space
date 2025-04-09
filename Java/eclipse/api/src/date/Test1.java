package date;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Test1 {

	public static void main(String[] args) throws ParseException {
		// TODO Auto-generated method stub
		String str = "2000-11-11";

		SimpleDateFormat sdf1 = new SimpleDateFormat("yyyy-MM-dd");

		Date day = sdf1.parse(str);

		SimpleDateFormat sdf2 = new SimpleDateFormat("yyyy年MM月dd日 EE");

		String resu = sdf2.format(day);

		System.out.println(resu);

	}

}
