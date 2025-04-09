package clock;

import java.util.Scanner;

public class Clock {
	private Display hour ;
	private Display minute ;
	private Display second ;
	public Clock (int h,int m,int s) {
		hour = new Display(h,24);
		minute = new Display(m,60);
		second = new Display(s,60);
		
	}
	public void increase() {
		second.increase();
		if (second.getValue() == 0) {
			minute.increase();
			if (minute.getValue() == 0) {
				hour.increase();
			}
		}
		
	}
		public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		Clock cl = new Clock(in.nextInt(),in.nextInt(),in.nextInt());
		for (int i = 0; i < 10000; i++) {
			System.out.printf("%02d:%02d:%02d\n",cl.hour.getValue(),cl.minute.getValue(),cl.second.getValue());
			cl.increase();
		}

	}

}
