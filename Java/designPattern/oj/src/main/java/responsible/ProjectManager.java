package responsible;

public class ProjectManager extends Manager{
    @Override
    public boolean handle(int fee) {
        if (fee < 1000)
            System.out.println("ProjectManager pass");
        else superior.handle(fee);
        return true;
    }
}
