package guida.day06;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import javax.sql.DataSource;
import java.sql.SQLException;

public class Test {
    public static DataSource ds = null;

    // 初始化C3P0数据库连接池
    static {
        // 使用c3p0-config.xml配置文件中的named-config节点中name属性的值
        ComboPooledDataSource cpds = new ComboPooledDataSource("");
        // 或指定数据源名称
//        ComboPooledDataSource cpds = new ComboPooledDataSource("test");
        ds = cpds;
    }

    public static void main(String[] args) throws SQLException {
        System.out.println(ds.getConnection());
    }
}
