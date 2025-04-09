package state;

class Turnstile

{   private  TurnstileState lockedState;

    private  TurnstileState unlockedState;

    private TurnstileState state = lockedState;

    public Turnstile(){
        lockedState=new LockedTurnstileState(this);
        unlockedState=new UnLockedTurnstileState(this);
    }

    public TurnstileState getLockedState() {
        return lockedState;
    }

    public TurnstileState getUnlockedState() {
        return unlockedState;
    }

    public void setState(TurnstileState state){
        this.state=state;
    }

    public void coin(){
        state.coin();
    }

    public void pass(){
        state.pass();
    }

    public void unLock(){
        System.out.println("turnstile unlock");
    }

    public void lock(){
        System.out.println("turnstile lock");
    }

    public void alarm(){
        System.out.println("alarm");
    }

    public void thankYou(){
        System.out.println("think you");
    }
}

