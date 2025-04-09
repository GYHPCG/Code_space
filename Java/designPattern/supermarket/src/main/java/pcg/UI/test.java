package pcg.UI;

import javax.swing.*;

public class test {
    public static void main(String[] args) {

        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new frame();
            }
        });
    }
}
