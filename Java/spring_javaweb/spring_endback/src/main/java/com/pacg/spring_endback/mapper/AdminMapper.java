package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.result.request.AdminPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import org.apache.ibatis.annotations.Mapper;

import java.util.ArrayList;
import java.util.List;

@Mapper
public interface AdminMapper {

    ArrayList<Admin> listUser();

    List<Admin> page(AdminPageRequest userPageRequest);

    void addUser(Admin user);

    void deleteUser(Integer id);

    Admin getUser(Integer id);

    void updateInfo(Admin user);

    Admin getUserBypasswd(LoginRequest user);

    void updatePasswd(String name, String passwd, String newPasswd);

    Admin getUserByName(LoginRequest user);
}
