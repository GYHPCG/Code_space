package day1;

public abstract class Weapon {
    public void setWeapon() {
        System.out.print("拿起武器: ");
        attack();
    }
    protected abstract void attack();
}
