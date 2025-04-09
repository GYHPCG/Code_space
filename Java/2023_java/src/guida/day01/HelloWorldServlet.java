package guida.day01;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class HelloWorldServlet extends HttpServlet {
    @Override
    public void destroy() {
        //super.destroy();
        System.out.println("servlet destory");
    }

//    @Override
//    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        //super.service(req, resp);
//        System.out.println("服务启动");
//        resp.getWriter()
//                .write("hello, 211");
//
//        resp.setContentType("text/html;charset=utf-8");
//
//         String class1 = getServletConfig().getInitParameter("class1");
//         System.out.println(class1);
//        resp.getWriter().write(class1);
//    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8");
         //获取学校
         ServletContext schoolServlet = this.getServletConfig().getServletContext();

         String schoolName = schoolServlet.getInitParameter("school");
         //System.out.println(schoolName);

         // 将school参数存储在request中，以便传递给ForwardServlet.java
         req.setAttribute("school", schoolName);

         //转发
         req.getRequestDispatcher("/forward").forward(req, resp);


    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += i;
        }
        System.out.println(sum);
        System.out.println("doGet Method is finish");
    }

    @Override
    public void init() throws ServletException {
        //super.init();
        System.out.println("servlet init");
    }
}
