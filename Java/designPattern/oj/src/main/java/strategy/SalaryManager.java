package strategy;

import java.util.ArrayList;
import java.util.List;

public class SalaryManager{

    private List<Double> workHourList=new ArrayList<Double>();

    private SaryComputerStrategy strage;

    private double hourlyRate;



    public void setHourlyRate(double hourlyRate) {

        this.hourlyRate = hourlyRate;

    }





    public void setStrage(SaryComputerStrategy strage) {

        this.strage = strage;

    }

    public void addWorkHour(double h){

        workHourList.add(h);

    }

    public double computerSalary(){

        return  strage.computerSalary(workHourList,hourlyRate);

    }

}
