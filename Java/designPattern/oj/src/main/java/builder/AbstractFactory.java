package builder;

public abstract class AbstractFactory {
    protected abstract Wall createWall();
    protected abstract Door createDoor();
}
