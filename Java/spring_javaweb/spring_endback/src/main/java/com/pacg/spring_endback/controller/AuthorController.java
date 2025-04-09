package com.pacg.spring_endback.controller;

import cn.hutool.core.util.StrUtil;
import com.pacg.spring_endback.entity.Author;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.result.request.AuthorPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserUpdateRequest;
import com.pacg.spring_endback.service.AuthorService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.time.LocalDate;

@RestController
@CrossOrigin
@RequestMapping("/author")
public class AuthorController {
    @Autowired
    AuthorService authorService;

    @GetMapping("/list")
    public Result authorArrayList() {
        return Result.success(authorService.listAuthor());
    }
    //分页模糊查询
    @GetMapping("/page")
    public Result page(AuthorPageRequest userPageRequest) {
        return Result.success(authorService.page(userPageRequest));
    }

    //添加用户
    @PostMapping("/addAuthor")
    public Result addUser(@RequestBody Author user) {
        user.setJoinTime(LocalDate.now());
        authorService.addUser(user);
        return Result.success();
    }
    //获取作者信息
    @GetMapping("/getInfo/{id}")
    public Result getInfo(@PathVariable Integer id) {
        Author author = authorService.getUser(id);
        return Result.success(author);
    }

    @GetMapping("/getByName/{name}")
    public Result getByName(@PathVariable String name) {
        Author author = authorService.getByName(name);
        System.out.println("hhh: " + name);
        return Result.success(author);
    }
    //修改用户
    @PutMapping("/updateInfo")
    public Result updateInfo(@RequestBody Author user) {
        authorService.updateInfo(user);
        return Result.success();
    }
    //删除用户
    @DeleteMapping("/del/{id}")
    public Result deleteUser(@PathVariable Integer id) {
        authorService.deleteUser(id);
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
        authorService.register(user);
        return Result.success();
    }

    // 登录
    @PostMapping("/login")
    public Result login(@RequestBody LoginRequest user) {
        return Result.success(authorService.login(user));
    }

    @PutMapping("/updatePasswd")
    public Result updatePass(@RequestBody UserUpdateRequest user) {
        String name = user.getName();
        String passwd = user.getPasswd();
        String newPasswd = user.getNewPasswd();
        authorService.updatePass(name, passwd, newPasswd);
        return Result.success();
    }
}
