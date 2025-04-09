package builder;

import java.util.ArrayList;
import java.util.List;

public class Maze {
    List<Room> roomList=new ArrayList<>();
    public void addRoom(Room room){
        roomList.add(room);
    }
}
