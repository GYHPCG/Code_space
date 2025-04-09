package guida.day07.servlet;

import guida.day07.pojo.Book;
import guida.day07.service.impl.BookServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/getBookList")
public class getBooksList extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //接收用户数据(从业务层接收，即service)和响应给其他层
        String bookName = req.getParameter("bookName");
        String author = req.getParameter("author");
        String type = req.getParameter("type");
        String desc = req.getParameter("desc");
        //System.out.println("id"+ bookId + " bookName: " + bookName);
          //防止乱码，设置全局过滤编码
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=utf-8");

        BookServiceImpl bookService = new BookServiceImpl();
        List<Book> bookList = bookService.getBookList(bookName,author, type, desc);

        req.setAttribute("list", bookList);
        req.getRequestDispatcher("/book.jsp").forward(req,resp);
//        for (Book book : bookList) {
//            resp.getWriter().write(book.toString() + "<br>");
//        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
