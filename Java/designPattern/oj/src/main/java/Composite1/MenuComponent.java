package Composite1;

public abstract class MenuComponent {
    String des="";

    public String getDes() {

        return des;

    }

    public void setDes(String des) {

        this.des = des;

    }



    public MenuComponent(String s) {

        this.des = s;

    }

    public abstract   void print();

    public void addComponent(MenuComponent c){

        throw new UnsupportedOperationException("不能添加子节点");

    }
}
