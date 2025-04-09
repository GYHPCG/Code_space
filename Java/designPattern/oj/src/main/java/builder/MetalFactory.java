package builder;

public class MetalFactory extends AbstractFactory{
    @Override
    protected Wall createWall() {
        return new MetalWall();
    }

    @Override
    protected Door createDoor() {
        return new MetalDoor();
    }
}
