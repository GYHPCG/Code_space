package strategy;

import java.util.List;

public class SaryComputerStrategyOne implements SaryComputerStrategy{
    @Override
    public double computerSalary(List<Double> list, double rate) {

        double sum_hour = 0;
        double salary = 0;
        for (double aDouble : list) {
            sum_hour += aDouble;
            salary += aDouble * rate;
        }

        if (sum_hour > 160) {
            salary *= 1.2;
        }

        return salary;
    }
}
