package guida.day03;

import guida.pojo.Person;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/session")
public class session extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doGet(req, resp);
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=utf-8");

        //get session obj
        HttpSession session = req.getSession();

        //store thing to session
        //session.setAttribute("name", "GYH");
        session.setAttribute("person", new Person("Jack",11));
        //get session id
        String id = session.getId();

        //judge the session is new?

        if (session.isNew()) {
            //System.out.println("session创建： " + id);
            resp.getWriter().write("session刚创建：" + id + " ");
        } else {
            //System.out.println("session已经存在：" + id);
            resp.getWriter().write("session已经存在： " + id);
        }


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
