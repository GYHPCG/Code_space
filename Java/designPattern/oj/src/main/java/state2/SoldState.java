package state2;

class SoldState extends State {
    public SoldState(TissueMachine tissueMachine) {
        this.tissueMachine = tissueMachine;
    }

    @Override
    public void dispense() {
        System.out.println("A tissue comes out");
        if (tissueMachine.getCount() > 0) {
            tissueMachine.setState(tissueMachine.getNoQuarterState());
        } else {
            System.out.println("Oops, out of tissues");
            tissueMachine.setState(tissueMachine.getSoldOutState());
        }
    }

    @Override
    public void printState() {
        System.out.println("SoldState");
    }
}

