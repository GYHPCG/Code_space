package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.Author;
import com.pacg.spring_endback.result.request.AuthorPageRequest;
import com.pacg.spring_endback.result.request.LoginRequest;
import org.apache.ibatis.annotations.Mapper;

import java.util.ArrayList;
import java.util.List;

@Mapper
public interface AuthorMapper {

    ArrayList<Author> listAuthor();

    List<Author> page(AuthorPageRequest userPageRequest);

    void addUser(Author user);

    void deleteUser(Integer id);

    Author getUser(Integer id);

    void updateInfo(Author user);

    Author getUserByPasswd(LoginRequest user);

    void updatePasswd(String name, String passwd, String newPasswd);

    Author getUserByName(LoginRequest user1);

    Author getByName(String name);
}
