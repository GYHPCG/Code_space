package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserPageRequest;
import org.apache.ibatis.annotations.Mapper;

import java.util.ArrayList;
import java.util.List;

@Mapper
public interface UserMapper {
    ArrayList<User> listUser();
    List<User> page(UserPageRequest userPageRequest);

    void addUser(User user);

    void deleteUser(Integer id);

    User getUser(Integer id);

    void updateInfo(User user);

    void updatePasswd(String name, String passwd, String newPasswd);

    User getUserBypasswd(LoginRequest user);

    User getUserByName(LoginRequest user1);

    void sendCode(String code, String email);

    User getByEmail(String email, String code);

    void resetPasswd(String name, String passwd);
}
