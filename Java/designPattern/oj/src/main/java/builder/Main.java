package builder;

public class Main {
    public static void main(String[] args) {

        System.out.println("迷宫游戏开始");
        //创建金属房间
        AbstractFactory metalFactory = new MetalFactory();
        Game game = new Game();
        game.createMaze(metalFactory);

        //添加木头房间
        AbstractFactory woodFactory = new WoodFactory();
        game.createMaze(woodFactory);
        game.mazeShow();

    }
}
