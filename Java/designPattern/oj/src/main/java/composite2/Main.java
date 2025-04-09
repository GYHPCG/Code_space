package composite2;

public class Main {
    public static void main(String[] args){

        Composite computer=new Composite("计算机");

        Part mouse=new Part(30,"鼠标");

        Part keyBoard=new Part(40,"键盘");

        Part screen=new Part(800,"显示器");

        computer.addComponent(mouse);

        computer.addComponent(keyBoard);

        computer.addComponent(screen);

        Composite box=new Composite("机箱");

        Part mainBoard=new Part(800,"主板");

        Part displayCard=new Part(500,"显卡");

        Part disk=new Part(400,"硬盘");

        box.addComponent(mainBoard);

        box.addComponent(displayCard);

        box.addComponent(disk);

        computer.addComponent(box);

        System.out.println(box.computerPrice());

        System.out.println(computer.computerPrice());

    }
}
