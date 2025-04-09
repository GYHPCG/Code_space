package com.pacg.spring_endback.controller;

import cn.hutool.core.util.StrUtil;
import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.result.request.AdminPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserUpdateRequest;
import com.pacg.spring_endback.service.AdminService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@CrossOrigin
@RequestMapping("/admin")
public class AdminController {
    @Autowired
    AdminService adminService;

    @GetMapping("/list")
    public Result userArrayList() {
        return Result.success(adminService.listUser());
    }
    //分页模糊查询
    @GetMapping("/page")
    public Result page(AdminPageRequest userPageRequest) {
        return Result.success(adminService.page(userPageRequest));
    }

    //添加用户
    @PostMapping("/addUser")
    public Result addUser(@RequestBody Admin admin) {
        adminService.addUser(admin);
        return Result.success();
    }
    //获取用户信息
    @GetMapping("/getInfo/{id}")
    public Result getInfo(@PathVariable Integer id) {
        Admin user = adminService.getUser(id);
        return Result.success(user);
    }
    //修改用户
    @PutMapping("/updateInfo")
    public Result updateInfo(@RequestBody Admin user) {
        adminService.updateInfo(user);
        return Result.success();
    }
    //删除用户
    @DeleteMapping("/del/{id}")
    public Result deleteUser(@PathVariable Integer id) {
        adminService.deleteUser(id);
        return Result.success();
    }

    // 登录
    @PostMapping("/login")
    public Result login(@RequestBody LoginRequest user) {
      return Result.success(adminService.login(user));
    }

    @PostMapping("/register")
    public Result register(@RequestBody LoginRequest user) {
        if (StrUtil.isBlank(user.getName()) || StrUtil.isBlank(user.getPasswd())) {
            return Result.error("数据输入不合法");
        }
        if (!user.getConfirmPass().equals(user.getPasswd())) {
            return Result.error("两次密码不一致");
        }
        adminService.register(user);
        return Result.success();
    }

    @PutMapping("/updatePasswd")
    public Result updatePass(@RequestBody UserUpdateRequest user) {
        String name = user.getName();
        String passwd = user.getPasswd();
        String newPasswd = user.getNewPasswd();
        adminService.updatePass(name, passwd, newPasswd);
        return Result.success();
    }
}
