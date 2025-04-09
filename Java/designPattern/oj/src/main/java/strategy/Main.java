package strategy;

public class Main {

    public static void main(String[] args){

        SalaryManager salaryManager=new SalaryManager();

        salaryManager.setHourlyRate(50);

        salaryManager.addWorkHour(52);

        salaryManager.addWorkHour(40.5);

        salaryManager.addWorkHour(38.5);

        salaryManager.addWorkHour(60);

        salaryManager.setStrage(new SaryComputerStrategyOne());

        System.out.println(salaryManager.computerSalary());

        salaryManager.setStrage(new SaryComputerStrategyTwo());

        System.out.println(salaryManager.computerSalary());

    }

}
