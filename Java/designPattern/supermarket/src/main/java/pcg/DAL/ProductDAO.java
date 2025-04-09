package pcg.DAL;

import pcg.BLL.Product;

import java.util.HashMap;

public  class ProductDAO {
   static HashMap<String, Product> map1 = new HashMap<>();

    public ProductDAO() {
        map1.put("1", new Product(1,"巧克力",10));
        map1.put("2", new Product(2,"奶茶",15));
        map1.put("3", new Product(3,"咖啡",10));
        map1.put("4", new Product(4, "西瓜", 5));

    }


    public static Product get(String productNO) {
        return map1.get(productNO);
    }
}
