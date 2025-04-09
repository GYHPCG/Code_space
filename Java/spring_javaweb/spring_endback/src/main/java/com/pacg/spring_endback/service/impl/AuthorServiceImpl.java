package com.pacg.spring_endback.service.impl;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.pacg.spring_endback.Utils.TokenUtils;
import com.pacg.spring_endback.entity.Author;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.AuthorMapper;
import com.pacg.spring_endback.mapper.UserMapper;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.AuthorPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.service.AuthorService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class AuthorServiceImpl implements AuthorService {

    @Autowired
    AuthorMapper authorMapper;
    @Autowired
    UserMapper userMapper;

    @Override
    public ArrayList<Author> listAuthor() {
        return authorMapper.listAuthor();
    }

    @Override
    public Object page(AuthorPageRequest userPageRequest) {
        PageHelper.startPage(userPageRequest.getPageNumber(), userPageRequest.getPageSize());
        List<Author> users = authorMapper.page(userPageRequest);
        return new PageInfo<>(users);
    }

    @Override
    public void addUser(Author user) {
        userMapper.deleteUser(user.getId());
        authorMapper.addUser(user);
    }

    @Override
    public void deleteUser(Integer id) {
        authorMapper.deleteUser(id);
    }

    @Override
    public Author getUser(Integer id) {
        return authorMapper.getUser(id);
    }

    @Override
    public void updateInfo(Author user) {
        authorMapper.updateInfo(user);
    }

    @Override
    public LoginDTO login(LoginRequest user) throws serviceException {
        Author userByPasswd = authorMapper.getUserByPasswd(user);
        if (userByPasswd == null) {
            throw new serviceException("用户名或密码错误");
        }
        LoginDTO loginDTO = new LoginDTO();
        BeanUtils.copyProperties(userByPasswd, loginDTO);
        String token = TokenUtils.genToken(String.valueOf(userByPasswd.getId()), userByPasswd.getPasswd());
        loginDTO.setToken(token);
        return loginDTO;
    }

    @Override
    public void updatePass(String name, String passwd, String newPasswd) {
        authorMapper.updatePasswd(name, passwd, newPasswd);
    }

    @Override
    public void register(LoginRequest user1) {
        Author userDb = authorMapper.getUserByName(user1);

        if (null != userDb) {
            throw new serviceException("用户名已存在");
        }

        Author user = new Author();
        user.setName(user1.getName());
        user.setPasswd(user1.getPasswd());
        user.setRole(user1.getRole());
        authorMapper.addUser(user);
    }

    @Override
    public Author getByName(String name) {
        return authorMapper.getByName(name);
    }
}
