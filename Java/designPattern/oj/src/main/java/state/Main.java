package state;

public class Main {

    public static void main(String[] args){

        Turnstile turnstile=new Turnstile();

        turnstile.setState(turnstile.getLockedState());

        turnstile.coin();

        turnstile.coin();

        turnstile.pass();

        turnstile.pass();
    }
}


