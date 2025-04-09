package responsible;

public abstract class Manager {
    protected Manager superior;

    public abstract boolean handle(int fee);

    public  void setSuccessor(Manager superior){
        this.superior=superior;
    }
}
