package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserPageRequest;

import javax.mail.MessagingException;
import java.util.ArrayList;

public interface UserService {
    ArrayList<User> listUser();

    Object page(UserPageRequest userPageRequest);

    void addUser(User user);

    void deleteUser(Integer id);

    User getUser(Integer id);

    void updateInfo(User user);

    LoginDTO login(LoginRequest user) throws serviceException;

    void updatePass(String name, String passwd, String newPasswd);

    void register(LoginRequest user);

    User getByEmail(String email, String code);

    void updateByName(User user);

    void sendEmailCode(String email) throws MessagingException;
}
