package guida.day08.Servlet;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.util.List;

@WebServlet(value = "/UpLoadServlet",initParams = {@WebInitParam(name = "path",value = "E:")})
public class UploadServlet extends HttpServlet {

    private String path;

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //设置文件上传基本路径
        String savePath = path;

        try {
            //构造一个文件上传处理对象
            DiskFileItemFactory factory = new DiskFileItemFactory();
            ServletFileUpload upLoad = new ServletFileUpload(factory);

            //获得表单中提交内容
            List<FileItem> list = upLoad.parseRequest(req);

            for (FileItem fileItem : list) {
                //fileItem.isFormField()返回true表示是普通的表单组件
                //fileItem.isFormField()返回false表示是上传输入框
                if (fileItem.isFormField()) {
                    //getFieldName()方法获得普通表单组件的参数名
                    String FieldName = fileItem.getFieldName();
                    //获得该参数所对应的值并指定编码
                    String Content = fileItem.getString("UTF-8");
                    //为了后面可以把普通参数从request中拿出来
                    req.setAttribute(FieldName, Content);
                } else {
                    //getName()取得上传文件的名字
                    String fileName = fileItem.getName();
                    //避免文件名字重复
//                    fileName = System.currentTimeMillis() + fileName;
                    File file = new File(savePath, fileName);
                    //把上传文件进行指定目录
                    fileItem.write(file);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        //因为上面解析request中是数据后,把普通表单组件中的key和value放到了request中,所以这里可以拿出来
        System.out.println("request.getAttribute(\"username\") = " + req.getAttribute("username"));
    }

    @Override
    public void init() throws ServletException {
        path = this.getServletConfig().getInitParameter("path");
    }
}