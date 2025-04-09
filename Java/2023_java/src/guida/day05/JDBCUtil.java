package guida.day05;

import java.sql.*;
import java.util.ResourceBundle;

public class JDBCUtil {
    private static final String driver;
    private static final String url;
    private static final String user;
    private static final String pwd;
    static {
        // java.util.ResourceBundle 和java.util.properties 都可以用来读取配置文件
        ResourceBundle bundle = ResourceBundle.getBundle("db");
        driver = bundle.getString("driver");
        url = bundle.getString("url");
        user = bundle.getString("user");
        pwd = bundle.getString("password");
    }

    public static Connection getConnection(){
        Connection connection = null;
        try {
            // 加载驱动
            Class.forName(driver);
            // 获得数据库连接
            connection = DriverManager.getConnection(url, user, pwd);
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }

    public static void close(Connection connection, Statement statement, ResultSet resultSet){
        closeResultSet(resultSet);
        closeStatement(statement);
        closeConnection(connection);
    }
    public static void close(Connection connection, Statement statement){
        closeStatement(statement);
        closeConnection(connection);
    }

    public static void closeConnection(Connection connection){
        if (connection != null)
        {
            try {
                connection.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }

    public static void closeStatement(Statement statement){
        if (statement != null)
        {
            try {
                statement.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }


    public static void closeResultSet(ResultSet set){
        if (set != null)
        {
            try {
                set.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }
}