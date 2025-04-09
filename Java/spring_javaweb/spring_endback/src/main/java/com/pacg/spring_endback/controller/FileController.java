package com.pacg.spring_endback.controller;
import com.pacg.spring_endback.result.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.net.URLEncoder;

// 定义接口路径
@Slf4j
@RestController
@RequestMapping("/file")
public class FileController {
    @Value("${server.port:9099}")
    private String port;

    @Value("${ip:localhost}")
    private String ip;
    private static final String BASE_DIR = System.getProperty("user.dir") + "/file/";
    // 定义接口类型和二级路径，完整的接口url是：/file/upload
    @PostMapping("/upload")
    public Result upload(@RequestParam MultipartFile file) {
        // 获取文件的名称
        String fileName = file.getOriginalFilename();
        try {
            // 新建一个文件路径
            File uploadFile = new File(BASE_DIR + fileName);
            // 当父级目录不存在时，自动创建
            if (!uploadFile.getParentFile().exists()) {
                uploadFile.getParentFile().mkdirs();
            }
            //如果文件已存在，上传过
            if(uploadFile.exists()) {
                fileName = System.currentTimeMillis() + "_" + fileName;
                uploadFile = new File(BASE_DIR + fileName);
            }
            // 存储文件到电脑磁盘
            file.transferTo(uploadFile);

        } catch (IOException e) {
            e.printStackTrace();
        }
//        String userPath = "httP://localhost:9099/file/download?fileName=" + fileName;
        String userPath =  "http://" + ip + ":" + port + "/file/download?fileName=" + fileName;
        log.error("上传成功");
        return Result.success(userPath);
    }

    @GetMapping("/download")

    public void download(@RequestParam String fileName, HttpServletResponse response) {
        //  新建文件流，从磁盘读取文件流
        try (FileInputStream fis = new FileInputStream(BASE_DIR + fileName);
             BufferedInputStream bis = new BufferedInputStream(fis);
             OutputStream os = response.getOutputStream()) {    //  OutputStream 是文件写出流，讲文件下载到浏览器客户端
            // 新建字节数组，长度是文件的大小，比如文件 6kb, bis.available() = 1024 * 6
            byte[] bytes = new byte[bis.available()];
            // 从文件流读取字节到字节数组中
            bis.read(bytes);
            // 重置 response
            response.reset();
            // 设置 response 的下载响应头
            response.setContentType("application/octet-stream");
            response.setHeader("Content-disposition", "attachment;filename=" + URLEncoder.encode(fileName, "UTF-8"));  // 注意，这里要设置文件名的编码，否则中文的文件名下载后不显示
            // 写出字节数组到输出流
            os.write(bytes);
            // 刷新输出流
            os.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

