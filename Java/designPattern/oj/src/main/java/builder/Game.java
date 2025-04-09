package builder;

public class Game {
    private Maze maze;
    private AbstractFactory factory;
    private int roomId;

    public Game() {
        this.maze = new Maze();
        roomId = 1;
    }

    public void createMaze(AbstractFactory factory){
        this.factory = factory;
        // 使用工厂创建房间组件
        Wall north = factory.createWall();
        Wall east = factory.createWall();
        Wall south = factory.createWall();
        Wall west = factory.createWall();
        Door door = factory.createDoor();

        // 创建房间并添加到迷宫中
        Room r1 = new Room(roomId++);
        Room r2 = new Room(roomId++);
        r1.setEastSide(door);
        r1.setNorthSide(north);
        r1.setSouthSie(south);
        r1.setWestSide(west);

        r2.setEastSide(east);
        r2.setNorthSide(north);
        r2.setSouthSie(south);
        r2.setWestSide(door);
        maze.addRoom(r1);
        maze.addRoom(r2);
    }
    public void mazeShow() {
        for (Room room : maze.roomList) {
            System.out.println("房间号为：" + room.getRoomNo() + "的状况为：");
            System.out.print("东面：");
            room.getEastSide().show();
            System.out.print("南面：");
            room.getSouthSie().show();
            System.out.print("西面：");
            room.getWestSide().show();
            System.out.print("北面：");
            room.getNorthSide().show();
        }
    }
}
