package builder;

public class Room {
    private int roomNo; //房间号
    private Side northSide;
    private Side eastSide;
    private Side southSie;
    private Side westSide;
    public Room(int roomNo){
        this.roomNo=roomNo;
    }

    public Room() {
    }

    public Room(int roomNo, Side northSide, Side eastSide, Side southSie, Side westSide) {
        this.roomNo = roomNo;
        this.northSide = northSide;
        this.eastSide = eastSide;
        this.southSie = southSie;
        this.westSide = westSide;
    }

    /**
     * 获取
     * @return roomNo
     */
    public int getRoomNo() {
        return roomNo;
    }

    /**
     * 设置
     * @param roomNo
     */
    public void setRoomNo(int roomNo) {
        this.roomNo = roomNo;
    }

    /**
     * 获取
     * @return northSide
     */
    public Side getNorthSide() {
        return northSide;
    }

    /**
     * 设置
     * @param northSide
     */
    public void setNorthSide(Side northSide) {
        this.northSide = northSide;
    }

    /**
     * 获取
     * @return eastSide
     */
    public Side getEastSide() {
        return eastSide;
    }

    /**
     * 设置
     * @param eastSide
     */
    public void setEastSide(Side eastSide) {
        this.eastSide = eastSide;
    }

    /**
     * 获取
     * @return southSie
     */
    public Side getSouthSie() {
        return southSie;
    }

    /**
     * 设置
     * @param southSie
     */
    public void setSouthSie(Side southSie) {
        this.southSie = southSie;
    }

    /**
     * 获取
     * @return westSide
     */
    public Side getWestSide() {
        return westSide;
    }

    /**
     * 设置
     * @param westSide
     */
    public void setWestSide(Side westSide) {
        this.westSide = westSide;
    }

    public String toString() {
        return "Room{roomNo = " + roomNo + ", northSide = " + northSide + ", eastSide = " + eastSide + ", southSie = " + southSie + ", westSide = " + westSide + "}";
    }

}
