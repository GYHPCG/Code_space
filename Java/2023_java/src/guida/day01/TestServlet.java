package guida.day01;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.plaf.synth.SynthOptionPaneUI;
import java.io.IOException;

@WebServlet("/test")
public class TestServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doGet(req, resp);
        System.out.println("Get");
        resp.getWriter().write("Get");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.doPost(req, resp);
//        System.out.println("Post");
//        resp.getWriter().write("Post");
        req.setCharacterEncoding("UTF-8");
        String name = req.getParameter("username");
        String passwd = req.getParameter("password");
        resp.setContentType("text/html;charset=UTF-8");
        resp.setStatus(512);
        if (name.equals("zs") && passwd.equals("123"))
            resp.getWriter().write("True");
        else resp.getWriter().write("False 对的");
        System.out.println("你好");


        //测试路径

        System.out.println(req.getContextPath());
        System.out.println(req.getServletPath());

        System.out.println(req.getRequestURI());

        System.out.println(req.getRequestURL());
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doPut(req, resp);
        System.out.println("Put");
        resp.getWriter().write("PUT");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doDelete(req, resp);
        System.out.println("Delete");
        resp.getWriter().write("Delete");
    }

//    @Override
//    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.service(req, resp);
//    }
}
