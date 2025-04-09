package strategy2;

public class Main {

    public static void main(String[] args) {

        BrakeBehavior brake1 = new ShortWheelBrake();

        BrakeBehavior brake2 = new LongWheelBrake();

        Car car = new ShortWheelCar(brake1);

        car.brake();

        car = new LongWheelCar(brake2);

        car.brake();

    }

}
