package strategy2;

public class ShortWheelBrake implements BrakeBehavior{
    @Override
    public void stop() {
        System.out.println("Simulate short tire brake marks!");
    }
}
