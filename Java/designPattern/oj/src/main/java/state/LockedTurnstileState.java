package state;

public class LockedTurnstileState implements TurnstileState{
    private Turnstile state;
    public LockedTurnstileState(Turnstile state) {
        this.state = state;
    }

    @Override
    public void coin() {
        state.unLock();
        state.setState(state.getUnlockedState());
    }

    @Override
    public void pass() {
        state.alarm();
    }
}
