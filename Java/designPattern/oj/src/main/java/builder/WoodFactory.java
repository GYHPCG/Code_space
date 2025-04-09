package builder;

public class WoodFactory extends AbstractFactory{
    @Override
    protected Wall createWall() {
        return new WoodWall();
    }

    @Override
    protected Door createDoor() {
        return new WoodDoor();
    }
}
