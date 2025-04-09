package sample.DAL;

import sample.DAL.ProductDAO;

import sample.BLL.Product;

import java.util.HashMap;

public class ProductDAO {

    HashMap<String, Product> map=new HashMap<>();
    public ProductDAO(){
        map.put("1",new Product("1","矿泉水",2,"瓶"));
        map.put("2",new Product("2","苹果",6,"斤"));
        map.put("3",new Product("3","洗手液",3.0,"瓶"));

    }

    public Product get(String productNO){
        return map.get(productNO);

    }
}
