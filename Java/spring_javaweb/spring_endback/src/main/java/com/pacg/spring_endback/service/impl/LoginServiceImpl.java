package com.pacg.spring_endback.service.impl;

import com.pacg.spring_endback.Utils.TokenUtils;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.LoginMapper;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.service.LoginService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class LoginServiceImpl implements LoginService {
    @Autowired
    LoginMapper loginMapper;
    @Override
    public LoginDTO login(LoginRequest user) throws serviceException {
        LoginDTO userDB = loginMapper.getUserByName(user);
        //用户是否存在
        if (userDB == null) {
            throw new serviceException("用户名或密码错误");
        }
        //判断用户是否被禁用
        if (userDB.getStatus() == false) {
            throw new serviceException("用户已经被禁止使用，请联系管理员处理");
        }

        LoginDTO loginDTO = new LoginDTO();
        BeanUtils.copyProperties(userDB, loginDTO);
        String token = TokenUtils.genToken(userDB.getName(), String.valueOf(userDB.getId()));
        loginDTO.setToken(token);
        return loginDTO;
    }

    @Override
    public LoginDTO getUserByName(String userName) {
        LoginDTO userDB = loginMapper.getByName(userName);
        return userDB;
    }
}
