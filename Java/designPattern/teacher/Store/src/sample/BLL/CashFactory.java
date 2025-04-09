package sample.BLL;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.lang.reflect.InvocationTargetException;
import java.util.Scanner;

public class CashFactory {
    public static CashSuper createCashAccept(){

        try {
            Scanner input=new Scanner(new FileInputStream("c:\\config.txt"));
            String type= input.nextLine();
            CashSuper cs=(CashSuper)Class.forName(type).getDeclaredConstructor().newInstance();

            return cs;

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        return new CashNormal();

    }
}
