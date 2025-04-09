package pcg.BLL;

import java.util.ArrayList;
import java.util.List;

public class Sale {
    static List<SaleItem> saleItems = new ArrayList<>();

    public static void addSaleItem(SaleItem item) {
        saleItems.add(item);

    }

    public double getTotal() {
        double sum = 0;
        for (SaleItem item : saleItems) {
            sum += item.getProduct().getPrice() * item.getQty();
        }
        return sum;

    }


}
