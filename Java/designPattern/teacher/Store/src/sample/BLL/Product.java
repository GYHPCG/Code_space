package sample.BLL;

public class Product {
    private String productNO;
    private String productDes;
    private double price;
    private String unit;

    public Product(String productNO, String productDes, double price, String unit) {
        this.productNO = productNO;
        this.productDes = productDes;
        this.price = price;
        this.unit = unit;
    }

    public String getProductNO() {
        return productNO;
    }

    public void setProductNO(String productNO) {
        this.productNO = productNO;
    }

    public String getProductDes() {
        return productDes;
    }

    public void setProductDes(String productDes) {
        this.productDes = productDes;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getUnit() {
        return unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }
}
