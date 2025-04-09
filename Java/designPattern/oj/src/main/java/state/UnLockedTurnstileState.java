package state;

public class UnLockedTurnstileState implements TurnstileState{
    private Turnstile state;
    public UnLockedTurnstileState(Turnstile state) {
        this.state = state;
    }
    @Override
    public void coin() {
        state.thankYou();
    }

    @Override
    public void pass() {
        state.lock();
        state.setState(state.getLockedState());
    }
}
