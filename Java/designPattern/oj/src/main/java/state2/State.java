package state2;

public abstract class State {
    protected TissueMachine tissueMachine;

    public void insertQuarter()//投币
    {
    }


    public void ejectQuarter()//退币
    {
    }



    public void turnCrank() //按下“出纸巾”按钮

    {

    }


    public void dispense() //出纸巾
    {

    }


    public abstract void printState();
}
