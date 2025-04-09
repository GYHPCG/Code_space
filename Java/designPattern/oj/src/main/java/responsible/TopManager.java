package responsible;

public class TopManager extends Manager{
    @Override
    public boolean handle(int fee) {
        if (fee < 10000)
            System.out.println("TopManager pass");
        else System.out.println("TopManager refuse");
        return true;
    }
}
