package gcp.homeWork.test3.test35;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MyDate extends java.util.Date{
    private long date;
    private String format;
    public Date d;
    private String s;
    public MyDate() {
        d = new Date();
        SimpleDateFormat format1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        s = format1.format(d);

    }

    public MyDate(long date, String format) {
        this.date = date;
        d = new Date(date);
        SimpleDateFormat format1 = new SimpleDateFormat(format);
        this.format = format;
        s = format1.format(d);
    }

    /**
     * 获取
     * @return date
     */
    public int getDate() {
        return (int)date;
    }

    /**
     * 设置
     * @param date
     */
    public void setDate(long date) {
        this.date = date;
    }

    /**
     * 获取
     * @return format
     */
    public String getFormat() {
        return format;
    }

    /**
     * 设置
     * @param format
     */
    public void setFormat(String format) {
        this.format = format;
    }

    public String toString() {

        return s;
    }
}
