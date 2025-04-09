package observer2;

public class Brodacast extends Observer {
    private Warner warner;
    public Brodacast(Warner wa) {
        this.warner = wa;
    }
    @Override
    public void update() {
        System.out.println("通知Brodacast: " + warner.getState());
    }
}
