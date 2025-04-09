package com.pacg.spring_endback.common;

import cn.hutool.core.util.StrUtil;
import com.auth0.jwt.JWT;
import com.auth0.jwt.JWTVerifier;
import com.auth0.jwt.algorithms.Algorithm;
import com.auth0.jwt.exceptions.JWTVerificationException;
import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.service.AdminService;
import com.pacg.spring_endback.service.LoginService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpMethod;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Enumeration;

@Component
@Slf4j
public class JwtInterceptor implements HandlerInterceptor {

    private static final String ERROR_CODE_401 = "401";

    @Autowired
//    private AdminService adminService;
    private LoginService loginService;

    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) {

        Enumeration<String> headerNames = request.getHeaderNames();
        System.out.println("Test: ");
        while (headerNames.hasMoreElements()) {
            String headerName = headerNames.nextElement();
            String headerValue = request.getHeader(headerName);
            System.out.println(headerName + ": " + headerValue);
        }

        System.out.println("header is over");

        if (HttpMethod.OPTIONS.toString().equals(request.getMethod())) {
            System.out.println("OPTIONS请求，放行");
            return true;
        }

        String token = request.getHeader("token");
        System.out.println("tokenis: " + token);

        if (StrUtil.isBlank(token)) {
            token = request.getParameter("token");
        }

        // 执行认证
        if (StrUtil.isBlank(token)) {
            throw new serviceException(ERROR_CODE_401, "无token，请重新登录");
        }
        // 获取 token 中的adminId
//        String adminId;
//        Admin admin;
        String userName;
        LoginDTO loginDTO;
        try {
//            adminId = JWT.decode(token).getAudience().get(0);
            System.out.println("jwt: " + JWT.decode(token).getAudience().toString());
            userName = JWT.decode(token).getAudience().get(0);
            // 根据token中的userid查询数据库
//            admin = adminService.getUser(Integer.parseInt(adminId));
            loginDTO = loginService.getUserByName(userName);

        } catch (Exception e) {
            String errMsg = "token验证失败，请重新登录";
            log.error(errMsg + ", token=" + token, e);
            throw new serviceException(ERROR_CODE_401, errMsg);
        }
        if (loginDTO == null) {
            throw new serviceException(ERROR_CODE_401, "用户不存在，请重新登录");
        }

        try {
            // 用户密码加签验证 token
            JWTVerifier jwtVerifier = JWT.require(Algorithm.HMAC256(String.valueOf(loginDTO.getId()))).build();
            System.out.println("tokenyesyhhhh");
            jwtVerifier.verify(token); // 验证token
            System.out.println("yesyhhhh");
        } catch (JWTVerificationException e) {
            System.out.println("异常： " + e);
            throw new serviceException(ERROR_CODE_401, "token验证失败，请重新登录");
        }
        return true;
    }
}

