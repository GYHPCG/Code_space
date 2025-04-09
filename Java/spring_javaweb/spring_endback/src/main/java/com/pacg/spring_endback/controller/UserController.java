package com.pacg.spring_endback.controller;

import cn.hutool.core.util.StrUtil;
import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserPageRequest;
import com.pacg.spring_endback.result.request.UserUpdateRequest;
import com.pacg.spring_endback.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@CrossOrigin
@RequestMapping("/user")
public class UserController {
    @Autowired
    UserService userService;

    @GetMapping("/list")
    public Result userArrayList() {
        return Result.success(userService.listUser());
    }
    //分页模糊查询
    @GetMapping("/page")
    public Result page(UserPageRequest userPageRequest) {
        return Result.success(userService.page(userPageRequest));
    }

    //添加用户
    @PostMapping("/addUser")
    public Result addUser(@RequestBody User user) {
        userService.addUser(user);
        return Result.success();
    }
    //获取用户信息
    @GetMapping("/getInfo/{id}")
    public Result getInfo(@PathVariable Integer id) {
        User user = userService.getUser(id);
        return Result.success(user);
    }
    //修改用户
    @PutMapping("/updateInfo")
    public Result updateInfo(@RequestBody User user) {
        userService.updateInfo(user);
        return Result.success();
    }
    //删除用户
    @DeleteMapping("/del/{id}")
    public Result deleteUser(@PathVariable Integer id) {
        userService.deleteUser(id);
        return Result.success();
    }
    @PostMapping("/register")
    public Result register(@RequestBody LoginRequest user) {
        if (StrUtil.isBlank(user.getName()) || StrUtil.isBlank(user.getPasswd()) || StrUtil.isBlank(user.getRole())) {
            return Result.error("数据输入不合法");
        }
        if (!user.getConfirmPass().equals(user.getPasswd())) {
            return Result.error("两次密码不一致");
        }
        userService.register(user);
        return Result.success();
    }

    // 登录
    @PostMapping("/login")
    public Result login(@RequestBody LoginRequest user) {
        return Result.success(userService.login(user));
    }

    @PutMapping("/updatePasswd")
    public Result updatePass(@RequestBody UserUpdateRequest user) {
        String name = user.getName();
        String passwd = user.getPasswd();
        String newPasswd = user.getNewPasswd();
        userService.updatePass(name, passwd, newPasswd);
        return Result.success();
    }
    @GetMapping("/getByID")
    public Result getByName(@RequestParam Integer id) {
     return Result.success(userService.getUser(id));
    }
}
