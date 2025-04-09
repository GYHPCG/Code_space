package guida.day05;

import com.sun.source.util.DocSourcePositions;
import guida.pojo.User;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

@WebServlet("/getUser")
public class ResultSetTest2 extends HttpServlet {
//    public static void main(String[] args) throws SQLException {
//        //1. 创建dao对象
//        BaseDao baseDao = new BaseDao();
//
//        //2. 创建sql语句
//        String sql = "select * from user";
//
//        //3. 获取查询结果
//        ArrayList<User>  result_list = (ArrayList<User>) baseDao.query(sql, new BeanListHandler(User.class));
//
//        for (User user : result_list) {
//            System.out.println(user);
//        }
//    }


    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        BaseDao baseDao = new BaseDao();

        //2. 创建sql语句
        String sql = "select * from user";

        //3. 获取查询结果
        ArrayList<User> result_list = null;
        try {
            result_list = (ArrayList<User>) baseDao.query(sql, new BeanListHandler(User.class));
        } catch (SQLException e) {
            e.printStackTrace();
        }

        for (User user : result_list) {
            System.out.println(user);
            resp.getWriter().write(user.getName());
        }
    }
}
