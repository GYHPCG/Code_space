package composite2;

public abstract class Component {
    String des="";
    public String getDes() {

        return des;

    }

    public void setDes(String des) {

        this.des = des;

    }

    public Component(String s) {

        this.des = s;

    }

    public abstract  double  computerPrice();

    public void addComponent(Component c){
        throw new UnsupportedOperationException("不能添加子节点");
    }
}
