package gcp.homeWork.test3.test31;

public class Role {
    private Weapon p;
    public Role(){};
    public void setWeapon(Weapon w) {
        //w.use();
        p = w;
    }
    public void use() {
        p.use();
    }

    public static void main(String[] args) {
        Role r= new Role();
        r.setWeapon(new Knife());
        r.use();
        r.setWeapon(new Sword());
        r.use();
    }
}
