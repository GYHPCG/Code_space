package clock;

public class Display {
	private int value = 0;
	private int limit = 0;
	public Display(int v,int x) {
		value = v;
		limit = x;
	}
	public void increase() {
		value++;
		if (value == limit) {
			value = 0;
		}
	}
	public int getValue() {
		return value;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Display a1 = new Display(0,24);
		for(int i = 0; i <= 30; i++) {
			
			System.out.println(a1.getValue());
			a1.increase();
		}
	}

}
