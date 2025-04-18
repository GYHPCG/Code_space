package guida.day05;

import guida.pojo.User;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import java.sql.SQLException;
import java.util.ArrayList;

public class ResultSetTest1 {
    public static void testBeanHandler() throws SQLException {
        BaseDao basedao = new BaseDao();
        String sql = "select * from user where id=?";
        User user = (User) basedao.query(sql,
                new BeanHandler(User.class), 1);
        System.out.print("id为1的User对象的name值为：" + user.getName());
    }
    public static void main(String[] args) throws SQLException {
        testBeanHandler();
    }
}
