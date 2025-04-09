package responsible;

public class DepartmentManager extends Manager{
    @Override
    public boolean handle(int fee) {
        if (fee < 2000)
            System.out.println("DepartmentManager pass");
        else superior.handle(fee);
        return true;
    }
}
