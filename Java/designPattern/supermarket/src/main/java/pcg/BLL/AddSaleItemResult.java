package pcg.BLL;

public class AddSaleItemResult {
    private String Des;
    private double qty;
    private double total;

    public String getDes() {
        return Des;
    }

    public void setDes(String des) {
        Des = des;
    }

    public double getQty() {
        return qty;
    }

    public void setQty(double qty) {
        this.qty = qty;
    }

    public double getTotal() {

        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }
}
