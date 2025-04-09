package observer2;

import java.util.ArrayList;

public abstract class Warner {
    private ArrayList<Observer> list = new ArrayList();

    private String state;

    public void attach(Observer ob) {
        list.add(ob);

    }

    public void detach(Observer ob) {
        list.remove(ob);
    }

    public void notifyObserver() {
        for (Observer observer : list) {
            observer.update();
        }
    }
    public String getState() {
        return state;
    }
    public void setState(String state) {
        this.state = state;
    }
}
