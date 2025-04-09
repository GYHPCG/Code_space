package guida.day08.Servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;

@WebServlet(value = "/DownLoadServlet", initParams = {@WebInitParam(name = "path", value = "E:")})
public class DownloadServlet extends HttpServlet {
    private String path;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String filename = req.getParameter("filename");
        String filePath = path + "/" + filename;

        // 设置为下载application/x-download
        resp.setContentType("application/x-download");
        //resp.setContentType("application/octet-stream");

        // 设置下载时的文件名
        filename = URLEncoder.encode(filename, "UTF-8");
        resp.addHeader("content-disposition", "attachment;filename=" + filename);
        try {
            ServletOutputStream outputStream = resp.getOutputStream();
            FileInputStream fileInputStream = new FileInputStream(filePath);
            byte[] b = new byte[1024];
            int i = 0;
            while ((i = fileInputStream.read(b)) > 0) {
                outputStream.write(b, 0, i);
            }
            fileInputStream.close();
            outputStream.flush();
            outputStream.close();
        } catch (Exception e) {

        }
    }

    @Override
    public void init() throws ServletException {
        path = this.getServletConfig().getInitParameter("path");
    }
}
