package sample.BLL;

import java.util.ArrayList;
import java.util.List;

public class Sale {

    CashSuper cashSuper;

    public List<SaleItem> getSaleItems() {
        return saleItems;
    }

    List<SaleItem> saleItems=new ArrayList<>();

    public void addSaleItem(SaleItem item){
        saleItems.add(item);
    }

    public void setCashSuper(CashSuper cashSuper) {
        this.cashSuper = cashSuper;
    }

    public double getTotal(){
       return cashSuper.acceptCash(this);
    }


}
