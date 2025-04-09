package day1;

import java.sql.SQLOutput;

public class Main {
    public static void main(String[] args) {
        Character role1 = new Character();

        Weapon axe = new Axe();
        role1.doAttack(axe);

        Weapon gun = new Gun();
        role1.doAttack(gun);

        Weapon knife = new Knife();
        role1.doAttack(knife);

    }
}
