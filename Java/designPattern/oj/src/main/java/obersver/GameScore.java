package obersver;

import java.util.ArrayList;

/**补充完整GameScore 类并提交**/

class GameScore implements Subject{

    private String gameTime;//比赛进行时间

    private int homeScore;//主队得分

    private int visitorScore;//客队得分

    private ArrayList<Observer> list = new ArrayList<>();

    public void setScore(String gameTime,int homeScore,int visitorScore){

        this.gameTime=gameTime;

        this.homeScore=homeScore;

        this.visitorScore=visitorScore;

        notifyObserver();

    }

    @Override
    public void registerObserver(Observer o) {
            list.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
            list.remove(o);
    }

    @Override
    public void notifyObserver() {
        for (Observer observer : list) {
            observer.update(gameTime, homeScore,visitorScore);
        }
    }

    //....



}