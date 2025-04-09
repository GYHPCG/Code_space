package guida.day03;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8"); // 处理post乱码
        resp.setContentType("application/json; charset=utf-8"); // 响应内容的类型
        //        设置响应头允许ajax跨域访问
        resp.setHeader("Access-Control-Allow-Origin", "*"); // 允许所有的ip的可以访问
        resp.setHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE"); // 允许访问的方式
        resp.setHeader("Access-Control-Max-Age", "3600");  // 设置超时时间
        resp.setHeader("Access-Control-Allow-Headers", "token, Accept, Origin, X-Requested-With, Content-Type, Last-Modified");


       //返回数据时指定编码格式:utf-8
        resp.setContentType("application/json;charset=utf-8");

        resp.setCharacterEncoding("UTF-8");


        //获取姓名，密码
        String username = req.getParameter("name");
        String password = req.getParameter("passwd");
        System.out.println(username);
        System.out.println(password);
        System.out.println("hh: " + req.toString());

        if ("GYH".equals(username) && "123456".equals(password)) {
            HttpSession session = req.getSession();
            session.setAttribute("username", username);
            resp.getWriter().println("欢迎登录：" + username);

            //设置自动登录
            //如果勾选记住我选项，创建cookie
            if (null != req.getParameter("remember")) {
                Cookie cookie = new Cookie("username", username);
                //设置自动登录时间范围,一天之内
                cookie.setMaxAge(1 * 24 * 60 * 60);
                resp.addCookie(cookie);
            }

        } else {
               resp.sendRedirect("/?error=fail");
        }

    }
}
