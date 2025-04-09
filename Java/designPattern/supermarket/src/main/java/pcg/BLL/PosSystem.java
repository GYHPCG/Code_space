package pcg.BLL;

import pcg.DAL.ProductDAO;

public class PosSystem {
    Sale sale;

    public void startSale() {
        sale = new Sale();
    }

    public AddSaleItemResult addSaleItem(String productNO, double qty) {

        AddSaleItemResult result = new AddSaleItemResult();
        ProductDAO productDAO = new ProductDAO();
        Product product = ProductDAO.get(productNO);

        SaleItem item = new SaleItem(product, qty);
        Sale.addSaleItem(item);
        double total = sale.getTotal();

        result.setDes(product.getProductDes());
        result.setQty(qty);
        result.setTotal(total);
        return result;
    }

    public double get_price(String productNO) {
        ProductDAO productDAO = new ProductDAO();
        Product product = ProductDAO.get(productNO);
        return product.getPrice();
    }

    public double endSale(double pay) {
        double total = sale.getTotal();
        double balance = pay - total;
        System.out.println("PP:" + pay + " " + total);
        System.out.println("bal: " + balance);

        return balance;
    }
}
