package decorator2;

import java.io.FilterReader;
import java.io.IOException;
import java.io.Reader;

public class LowerCaseStringReader extends FilterReader {
    /**
     * Creates a new filtered reader.
     *
     * @param in a Reader object providing the underlying stream.
     * @throws NullPointerException if {@code in} is {@code null}
     */
    Reader in;

    protected LowerCaseStringReader(Reader in) {
        super(in);
        this.in = in;
    }

    @Override
    public int read() throws IOException {
        //System.out.println(" num: " + super.read());
        //return super.read();
        int c = super.read();
        if (c != -1) {
            return Character.toLowerCase((char) c);
        }
        return -1;

    }
}
