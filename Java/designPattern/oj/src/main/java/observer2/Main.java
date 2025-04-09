package observer2;

public class Main {
    public static void main(String[] args) {
        FireWarner fireWarner = new FireWarner();

        Brodacast brodacast = new Brodacast(fireWarner);
        TV tv = new TV(fireWarner);

        fireWarner.attach(brodacast);
        fireWarner.attach(tv);

        fireWarner.setState("着火了");
        //fireWarner.setState("需要水");
        fireWarner.notifyObserver();
    }
}
