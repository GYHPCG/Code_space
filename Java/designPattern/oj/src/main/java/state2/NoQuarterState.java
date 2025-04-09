package state2;

class NoQuarterState extends State {
    public NoQuarterState(TissueMachine tissueMachine) {
        this.tissueMachine = tissueMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("You inserted a quarter");
        tissueMachine.setState(tissueMachine.getHasQuarterState());
    }

    @Override
    public void printState() {
        System.out.println("NoQuarterState");
    }
}




