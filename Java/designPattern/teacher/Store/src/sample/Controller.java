package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import sample.BLL.AddSaleItemResult;
import sample.BLL.PosSystem;

public class Controller {

    @FXML
    TextField teProductNO;

    @FXML
    TextField teQty;

    @FXML
    TextField teMoney;

    @FXML
    Label lbTotal;

    @FXML
    Label lbReturnMoney;

    PosSystem posSystem =new PosSystem();

    public void btnStartClick(){
        posSystem.startSale();

        lbTotal.setText("");
        lbReturnMoney.setText("");
        teQty.setText("");
        teProductNO.setText("");
        teMoney.setText("");
    }

    public void btnAddSaleItemClick(){
        String productNO=teProductNO.getText();
        double qty=Double.parseDouble(teQty.getText().trim());

        AddSaleItemResult result=posSystem.addSaleItem(productNO,qty);

        lbTotal.setText(result.getDes()+" "+result.getQty()+" 总价"+result.getTotal());


        teQty.setText("");
        teProductNO.setText("");

    }

    public void btEndSaleClick(){
        double money=Double.parseDouble(teMoney.getText().trim());
        double returnMoney= posSystem.endSale(money);


        lbReturnMoney.setText("找零"+String.valueOf(returnMoney));
    }
}
