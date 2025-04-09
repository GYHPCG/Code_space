package strategy;

import java.util.List;

public class SaryComputerStrategyTwo implements SaryComputerStrategy{
    @Override
    public double computerSalary(List<Double> list, double rate) {
        double salary = 0;
        for (double aDouble : list) {
            if (aDouble > 40) {
                aDouble *= 1.2;
            }

            salary += aDouble * rate;
        }

        return salary;
    }
}
