package strategy2;

public class Car {
    BrakeBehavior brakeBehavior;

    public Car(BrakeBehavior b) {
        brakeBehavior = b;
    }

    public void brake() {
        brakeBehavior.stop();
    };
}
