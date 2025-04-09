package guida.day04;


import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

// @WebServlet("/getUserList")
public class GetUserListServlet {

    private static String driver = "com.mysql.cj.jdbc.Driver";
    private static String DB_URL = "jdbc:mysql://localhost/panchenggong?serverTimezone=GMT%2B8";

    //设置账号密码
    private static String username = "root";
    private static String password = "pcg20010812";

    public static void main(String[] args) throws ClassNotFoundException {


        Connection conn = null;
        Statement stmt = null;
        try {
        //STEP2:注册JDBC驱动
            Class.forName(driver);
          //STEP3:建立一个连接
            System.out.println("建立一个连接");
            conn = DriverManager.getConnection(DB_URL, username, password);


            //STEP4:执行一次查询操作
            System.out.println("执行操作");
            stmt = conn.createStatement();
            String sql;
            sql = "SELECT Sno,Sname,Sage, Ssex FROM student";
            ResultSet rs = stmt.executeQuery(sql);
            //STEP5:获取结果并打印
            while (rs.next()) {
                //Retrievebycolumnname
                String id = rs.getString("Sno");
                String name = rs.getString("Sname");
                String age = rs.getString("Sage");
                String sex = rs.getString("Ssex");
//Displayvalues
                System.out.print("ID:" + id);
                System.out.print(",Name:" + name);
                System.out.print(",Age:" + age);
                System.out.println(",Sex:" + sex);
            }
            //STEP6:关闭连接
            rs.close();
            stmt.close();
            conn.close();
        } catch (Exception se) {
            //处理JDBC异常
            se.printStackTrace();

        } finally {
            try {
                if (stmt != null)
                    stmt.close();
            } catch (SQLException se2) {

            }//nothingwecando
            try {
                if (conn != null)
                    conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }//endfinallytry
        }//endtry

        System.out.println("Goodbye!");
    }
//finally处理块关闭资源

}

