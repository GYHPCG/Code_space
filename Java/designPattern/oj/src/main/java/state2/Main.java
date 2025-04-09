package state2;

public class Main {
    public static void main(String[] args) {

        TissueMachine tissueMachine = new TissueMachine(10);

        tissueMachine.printState();

        tissueMachine.insertQuarter();

        tissueMachine.printState();

        tissueMachine.ejectQuarter();

        tissueMachine.printState();

        tissueMachine.insertQuarter();

        tissueMachine.printState();

        tissueMachine.turnCrank();

        tissueMachine.printState();

        tissueMachine.dispense();

        tissueMachine.printState();

    }
}
