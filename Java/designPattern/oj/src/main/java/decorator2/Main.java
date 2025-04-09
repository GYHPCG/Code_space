package decorator2;

import java.io.IOException;
import java.io.StringReader;

public class Main {

    public static void main(String[] args) throws IOException {

        LowerCaseStringReader r = new LowerCaseStringReader(new StringReader("Design Pattern"));

        int c;

        while ((c = r.read()) > 0) {
            //System.out.println("num: " + c);
            System.out.print((char) c);
        }
    }

}
