package com.pacg.spring_endback.Utils;

import cn.hutool.core.date.DateUtil;
import cn.hutool.core.util.StrUtil;
import com.auth0.jwt.JWT;
import com.auth0.jwt.algorithms.Algorithm;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.service.LoginService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.Date;

@Component
@Slf4j
public class TokenUtils {

//    private static AdminService staticAdminService;

    private static LoginService staticLoginService;
    @Resource
//    private AdminService adminService;
    private LoginService loginService;
    @PostConstruct
    public void setUserService() {
        staticLoginService = loginService;
    }

    /**
     * 生成token
     *
     * @return
     */
    public static String genToken(String userName, String userId) {
        return JWT.create().withAudience(userName) // 将 user id 保存到 token 里面,作为载荷
                .withExpiresAt(DateUtil.offsetDay(new Date(), 2)) // 2天后token过期
                .sign(Algorithm.HMAC256(userId)); // 以 password 作为 token 的密钥
    }

    /**
     * 获取当前登录的用户信息
     *
     * @return user对象
     *  /admin?token=xxxx
     */
    public static LoginDTO getCurrentAdmin() {
        String token = null;
        try {
            HttpServletRequest request = ((ServletRequestAttributes) RequestContextHolder.getRequestAttributes()).getRequest();
            token = request.getHeader("token");
            if (StrUtil.isBlank(token)) {
                token = request.getParameter("token");
            }
            if (StrUtil.isBlank(token)) {
                log.error("获取当前登录的token失败， token: {}", token);
                return null;
            }
//            String adminId = JWT.decode(token).getAudience().get(0);
            String userName = JWT.decode(token).getAudience().get(0);
//            return staticAdminService.getUser(Integer.valueOf(adminId));
            return staticLoginService.getUserByName(userName);
        } catch (Exception e) {
            log.error("获取当前登录的管理员信息失败, token={}", token,  e);
            return null;
        }
    }
}


