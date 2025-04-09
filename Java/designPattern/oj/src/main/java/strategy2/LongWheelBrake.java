package strategy2;

public class LongWheelBrake implements BrakeBehavior{
    @Override
    public void stop() {
        System.out.println("Simulate long tire brake marks!");
    }
}
