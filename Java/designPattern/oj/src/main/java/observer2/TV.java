package observer2;

public class TV extends Observer{
    private Warner warner;
    public TV(Warner wa) {
        this.warner = wa;
    }
    @Override
    public void update() {
        System.out.println("通知TV: " + warner.getState());
    }
}
