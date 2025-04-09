package com.pacg.spring_endback.service.impl;

import cn.hutool.core.util.StrUtil;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.pacg.spring_endback.Utils.TokenUtils;
import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.AdminMapper;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.AdminPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.service.AdminService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class AdminServiceImpl implements AdminService {
    @Autowired
    AdminMapper adminMapper;
    @Override
    public ArrayList<Admin> listUser() {
        return adminMapper.listUser();
    }

    @Override
    public Object page(AdminPageRequest adminPageRequest) {
        PageHelper.startPage(adminPageRequest.getPageNumber(), adminPageRequest.getPageSize());
        List<Admin> users = adminMapper.page(adminPageRequest);
        return new PageInfo<>(users);
    }

    @Override
    public void addUser(Admin user) {
        if (StrUtil.isBlank(user.getPasswd())) {
            System.out.println("llnjsdfksf");
            user.setPasswd("666666");
        }
        adminMapper.addUser(user);
    }

    @Override
    public void deleteUser(Integer id) {
        adminMapper.deleteUser(id);
    }

    @Override
    public Admin getUser(Integer id) {
        return adminMapper.getUser(id);
    }

    @Override
    public void updateInfo(Admin user) {
        adminMapper.updateInfo(user);
    }

    @Override
    public LoginDTO login(LoginRequest user) {
        Admin userBypasswd = adminMapper.getUserBypasswd(user);
        if (userBypasswd == null) {
            throw new serviceException("用户名或密码错误");
        }
        LoginDTO loginDTO = new LoginDTO();
        BeanUtils.copyProperties(userBypasswd, loginDTO);
        String token = TokenUtils.genToken(String.valueOf(userBypasswd.getId()), userBypasswd.getPasswd());
        loginDTO.setToken(token);
        return loginDTO;
    }

    @Override
    public void updatePass(String name, String passwd, String newPasswd) {
        adminMapper.updatePasswd(name, passwd, newPasswd);
    }

    @Override
    public void register(LoginRequest user) {
        Admin userDb = adminMapper.getUserByName(user);

        if (null != userDb) {
            throw new serviceException("用户名已存在");
        }

        Admin admin = new Admin();
        admin.setName(user.getName());
        admin.setPasswd(user.getPasswd());
        adminMapper.addUser(admin);
    }
}
