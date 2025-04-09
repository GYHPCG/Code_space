package sample;

import sample.BLL.AddSaleItemResult;
import sample.BLL.PosSystem;

public class Test {
    public static void main(String[] args){
        PosSystem posSystem=new PosSystem();
        posSystem.startSale();


        AddSaleItemResult r=posSystem.addSaleItem("1",1);
        System.out.println(r.getTotal());
        r=posSystem.addSaleItem("2",3);
        System.out.println(r.getTotal());

        double s=posSystem.endSale(100);
        System.out.println(s);



    }
}
