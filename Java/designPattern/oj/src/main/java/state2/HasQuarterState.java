package state2;

class HasQuarterState extends State {
    public HasQuarterState(TissueMachine tissueMachine) {
        this.tissueMachine = tissueMachine;
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Quarter returned");
        tissueMachine.setState(tissueMachine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("You turned...");
        tissueMachine.setState(tissueMachine.getSoldState());
    }

    @Override
    public void printState() {
        System.out.println("HasQuarterState");
    }
}