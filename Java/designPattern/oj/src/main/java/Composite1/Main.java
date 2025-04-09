package Composite1;

public class Main {
    public static void main(String[] args){

        MenuComponent news=new CompositeMenu("news");

        CompositeMenu chinaNews=new CompositeMenu("chinaNews");

        MenuComponent jpnNews=new MenuItem("jpnNews");

        MenuComponent gzNews=new MenuItem("GuiZhouNews");

        MenuComponent gdNews=new MenuItem("GuangDongNews");

        chinaNews.addComponent(gzNews);

        chinaNews.addComponent(gdNews);

        news.addComponent(chinaNews);

        news.addComponent(jpnNews);

        news.print();
    }
}
