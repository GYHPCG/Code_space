package sample.BLL;

import sample.DAL.ProductDAO;

public class PosSystem {
    Sale sale;
    public void startSale(){
        sale=new Sale();
        sale.setCashSuper(CashFactory.createCashAccept());

    }

    public AddSaleItemResult addSaleItem(String prodcutNO, double qty){

        AddSaleItemResult result=new AddSaleItemResult();

        ProductDAO productDAO=new ProductDAO();
        Product product=productDAO.get(prodcutNO);

        SaleItem item=new SaleItem(product,qty);

        sale.addSaleItem(item);

        double total=sale.getTotal();

        result.setDes(product.getProductDes());
        result.setQty(qty);
        result.setTotal(total);
        return result;
    }

    public double endSale(double pay){

        double total=sale.getTotal();
        return pay-total;

    }

}
