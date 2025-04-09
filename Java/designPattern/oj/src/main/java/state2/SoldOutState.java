package state2;

class SoldOutState extends State {
    public SoldOutState(TissueMachine tissueMachine) {
        this.tissueMachine = tissueMachine;
    }

    @Override
    public void printState() {
        System.out.println("SoldOutState");
    }
}


