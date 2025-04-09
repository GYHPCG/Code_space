package pcg.BLL;

public class Product {
    private int productNO;
    private String productDes;
    private double price;

    public Product(int productNO, String productDes, double price) {
        this.productNO = productNO;
        this.productDes = productDes;
        this.price = price;
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

    public int getProductNO() {
        return productNO;
    }

    public void setProductNO(int productNO) {
        this.productNO = productNO;
    }
}
