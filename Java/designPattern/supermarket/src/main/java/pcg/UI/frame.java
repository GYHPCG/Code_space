package pcg.UI;

import pcg.BLL.AddSaleItemResult;
import pcg.BLL.CashFractory;
import pcg.BLL.PosSystem;
import pcg.BLL.Strategy;
import pcg.DAL.ProductDAO;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class frame extends JFrame {

    private JTextField productNumberField;
    private JTextField quantityField;
    private JTextField discountField;
    private JTextArea displayArea;
    private double totalPrice;
    private CashFractory st = null;
    private PosSystem posSystem;
    private AddSaleItemResult addSaleItemResult;

    public frame() {

        posSystem = new PosSystem();
        posSystem.startSale();


        setTitle("超市收银系统");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        productNumberField = new JTextField(12);
        quantityField = new JTextField(12);
        discountField = new JTextField(4);
        displayArea = new JTextArea(10, 30);
        JButton calculateButton = new JButton("总价");
        JButton payButton = new JButton("返回现金");

        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculateTotalPrice();
            }
        });

        payButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                processPayment();
            }
        });

        panel.add(new JLabel("商品编号"));
        panel.add(productNumberField);
        panel.add(new JLabel("商品数量"));
        panel.add(quantityField);

        panel.add(new JLabel("折扣方式"));
        panel.add(discountField);

        panel.add(calculateButton);
        panel.add(payButton);

        panel.add(displayArea);

        add(panel);
        setVisible(true);
    }

    private void calculateTotalPrice() {

        try {

            int cashType = Integer.parseInt(discountField.getText());

            st = new CashFractory(cashType);

            String productNO = productNumberField.getText();
            int qty = Integer.parseInt(quantityField.getText());

            double price = posSystem.get_price(productNO);
            addSaleItemResult = posSystem.addSaleItem(productNO,qty);

            double subtotal = st.getResult(price, qty);

            System.out.println(subtotal);

            addSaleItemResult = posSystem.addSaleItem(productNO, qty);

            totalPrice += subtotal;

            displayArea.append("商品编号为： " + productNO + ", 数量为: " + qty + ", 该商品总价为: ¥" + subtotal + "\n");
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "无效的输入，请重新输入");
        }
    }

    private void processPayment() {

            double cashAmount = Double.parseDouble(JOptionPane.showInputDialog(this, "支付的现金为："));
            if (cashAmount < totalPrice) {
                JOptionPane.showMessageDialog(this, "商品总价大于您预支付的现金，请再次输入现金");
            } else {
                double balance = cashAmount - totalPrice;

                System.out.println(balance);
                displayArea.append("总价: ¥" + totalPrice + "\n");
                displayArea.append("输入现金为: ¥" + cashAmount + "\n");
                displayArea.append("找您: ¥" + balance + "\n");
                displayArea.append("欢迎下次光临!\n");

                totalPrice = 0.0;
            }
        }

}
