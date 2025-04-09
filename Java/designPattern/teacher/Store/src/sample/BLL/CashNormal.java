package sample.BLL;

public class CashNormal implements CashSuper {


    @Override
    public double acceptCash(Sale sale) {
        double total=0;

        for(SaleItem saleItem :sale.getSaleItems()){
            total+=saleItem.getProduct().getPrice()*saleItem.getQty();
        }

        return total;
    }
}
