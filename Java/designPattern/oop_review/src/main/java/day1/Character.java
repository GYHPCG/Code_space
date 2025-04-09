package day1;

public class Character  {
    public Character() {
        System.out.println("角色创建");
    }
    public void doAttack(Weapon weapon) {
        weapon.setWeapon();
    }
}
