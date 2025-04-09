package state2;

public class TissueMachine {
    private State soldOutState, noQuarterState, hasQuarterState, soldState, state;

    private int count; //纸巾数



    public TissueMachine(int numbers) {

        count = numbers;

        soldOutState = new SoldOutState(this);

        noQuarterState = new NoQuarterState(this);

        hasQuarterState = new HasQuarterState(this);

        soldState = new SoldState(this);

        state = noQuarterState;

    }



    public State getHasQuarterState() {

        return hasQuarterState;

    }



    public State getNoQuarterState() {

        return noQuarterState;

    }



    public State getSoldState() {

        return soldState;

    }



    public State getSoldOutState() {

        return soldOutState;

    }



    public int getCount() {

        return count;

    }



    public void setState(State state) {
        this.state = state;

    }

    public void printState() {
        this.state.printState();

    }


    public void insertQuarter()//投币
    {
        this.state.insertQuarter();
    }

    public void ejectQuarter()//退币
    {

        this.state.ejectQuarter();

    }

    public void turnCrank() //按下“出纸巾”按钮
    {
        this.state.turnCrank();

    }

    public void dispense() //出纸巾
    {

        this.state.dispense();

    }
}
