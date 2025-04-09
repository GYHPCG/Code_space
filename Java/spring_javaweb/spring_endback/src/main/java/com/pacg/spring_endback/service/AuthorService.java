package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.Author;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.AuthorPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;

import java.util.ArrayList;

public interface AuthorService {

    ArrayList<Author> listAuthor();

    Object page(AuthorPageRequest userPageRequest);

    void addUser(Author user);

    void deleteUser(Integer id);

    Author getUser(Integer id);

    void updateInfo(Author user);

    LoginDTO login(LoginRequest user) throws serviceException;

    void updatePass(String name, String passwd, String newPasswd);

    void register(LoginRequest user);

    Author getByName(String name);
}
