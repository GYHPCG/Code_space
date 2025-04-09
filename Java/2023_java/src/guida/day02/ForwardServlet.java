package guida.day02;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

// @WebServlet("/forward")
public class ForwardServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取班级
        String class1 = getServletConfig().getInitParameter("class1");

        // 获取学校,获取从HelloWorldServlet传递过来的school参数
        String school = (String) req.getAttribute("school");

        //获取表单提交的姓名，年龄，学号
        String username = req.getParameter("username");
        String age = req.getParameter("age");
        String id = req.getParameter("id");

        resp.setContentType("text/html;charset=utf-8");
        resp.getWriter().write("学校： " + school + "<br>" +
                "班级: " + class1 + "<br>" +
                "姓名：" + username + "<br>" +
                "年龄：" + age + "<br>" +
                "学号：" + id + "<br>"

        );
    }
}
