package com.pacg.spring_endback.exception;


import cn.hutool.core.util.StrUtil;
import com.pacg.spring_endback.result.Result;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

@ControllerAdvice
@Slf4j
public class ExceptionHandle {
    @ExceptionHandler(value =Exception.class)
    @ResponseBody
    public Result exceptionHandler(Exception e){
        System.out.println("exce: 全局异常捕获>>>:"+e);
        log.error("系统异常", e);
        return Result.error("系统异常");
    }

    @ResponseBody
    @ExceptionHandler(value =serviceException.class)
    public Result serviceExceptionHandler(serviceException e){
        System.out.println("service: 全局异常捕获>>>:"+e);
        log.error("系统异常", e);
        String code = e.getCode();
        if (StrUtil.isNotBlank(code)) {
            return Result.error(code, e.getMessage());
        }
        return Result.error(e.getMessage());
    }
}
