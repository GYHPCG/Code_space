package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.AdminPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;

import java.util.ArrayList;

public interface AdminService {
    ArrayList<Admin> listUser();

    Object page(AdminPageRequest userPageRequest);

    void addUser(Admin user);

    void deleteUser(Integer id);

    Admin getUser(Integer id);

    void updateInfo(Admin user);

    LoginDTO login(LoginRequest user) throws serviceException;

    void updatePass(String name, String passwd, String newPasswd);

    void register(LoginRequest user) throws serviceException;
}
