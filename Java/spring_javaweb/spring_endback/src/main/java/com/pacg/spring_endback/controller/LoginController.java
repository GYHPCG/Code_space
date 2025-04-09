package com.pacg.spring_endback.controller;

import cn.hutool.core.util.StrUtil;
import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.result.DTO.UserPasswordDTO;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.service.LoginService;
import com.pacg.spring_endback.service.UserService;
import org.hibernate.service.spi.ServiceException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.mail.MessagingException;

@RestController
@RequestMapping("/login")
public class LoginController {
    @Autowired
    LoginService loginService;
    @Autowired
    UserService userService;
    @PostMapping
    public Result login(@RequestBody LoginRequest user) {
        return Result.success(loginService.login(user));
    }

    @PutMapping("/reset")
    public Result reset(@RequestBody UserPasswordDTO userPasswordDTO) {
        if (StrUtil.isBlank(userPasswordDTO.getEmail()) || StrUtil.isBlank(userPasswordDTO.getCode())) {
            throw new ServiceException("参数异常");
        }
        // 如果验证通过了，就查询要不过户的信息
        User user = userService.getByEmail(userPasswordDTO.getEmail(), userPasswordDTO.getCode());
        if (user != null)  {
            // 重置密码
            user.setPasswd("123");
            userService.updateByName(user);
            return Result.success("密码重置成功，新密码为：123，请尽快登录修改初始密码");
        }
        return Result.error("验证码输入错误");
    }

    // 发送邮箱验证码
    @GetMapping("/email/{email}")
    public Result sendEmailCode(@PathVariable String email) throws MessagingException {
        if(StrUtil.isBlank(email)) {
            throw new ServiceException("参数错误");
        }
        userService.sendEmailCode(email);
        return Result.success();
    }
}
