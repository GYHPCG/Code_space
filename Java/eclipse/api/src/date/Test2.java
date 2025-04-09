package date;

import java.util.Calendar;
import java.util.Date;

public class Test2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Calendar c = Calendar.getInstance();
		Date d = new Date(0l);
		c.setTime(d);
		c.set(Calendar.YEAR, 2022);
//		System.out.println(c);
		c.add(Calendar.MONTH, 8);
		int year = c.get(Calendar.YEAR);
		int month = c.get(Calendar.MONTH) + 1;
		int day = c.get(Calendar.DAY_OF_MONTH);
		System.out.println(year + ", " + month + ", " + day);

	}

}
