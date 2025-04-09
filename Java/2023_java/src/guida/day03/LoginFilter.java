package guida.day03;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebFilter("/*")
public class LoginFilter implements Filter {
    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {

        HttpServletRequest Request = (HttpServletRequest) servletRequest;
        HttpServletResponse Response = (HttpServletResponse) servletResponse;


        Request.setCharacterEncoding("UTF-8"); // 处理post乱码
        Response.setContentType("application/json; charset=utf-8"); // 响应内容的类型
        //        设置响应头允许ajax跨域访问
        Response.setHeader("Access-Control-Allow-Origin", "*"); // 允许所有的ip的可以访问
        Response.setHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE"); // 允许访问的方式
        Response.setHeader("Access-Control-Max-Age", "3600");  // 设置超时时间
        Response.setHeader("Access-Control-Allow-Headers", "token, Accept, Origin, X-Requested-With, Content-Type, Last-Modified");


        //防止乱码，设置全局过滤编码
        Request.setCharacterEncoding("UTF-8");
        Response.setCharacterEncoding("UTF-8");
        Response.setContentType("text/html;charset=utf-8");

       //设置白名单
       //获取路径
        String servletPath = Request.getServletPath();
        System.out.println( "tt: " + servletPath);

        //登录拦截
        if (isWrite(servletPath)) {
            filterChain.doFilter(Request, Response);
        } else {
            if (Request.getSession().getAttribute("username") != null) {
                filterChain.doFilter(Request, Response);
            }
            else {
                //当不是白名单，没有session时，检测cookie是否存在
                Cookie[] cookies = Request.getCookies();
                boolean flag = false;
                for (Cookie val: cookies) {
                    if ("username".equals(val.getName())) {
                        flag = true;
                        Request.getSession().setAttribute(val.getName(), val.getValue());
                        filterChain.doFilter(Request,Response);
                        break;
                    }
                }
                if (!flag)
                     Response.sendRedirect("/");
            }
        }

    }

    private boolean isWrite(String path) {
        if ("/".equals(path) || ("/index.jsp".equals(path)) || "/login".equals(path) || "/img/70.png".equals(path) || "/getUserList".equals(path)) {
            return true;
        }
        return false;
    }
}
