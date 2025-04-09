package com.pacg.spring_endback.service.impl;

import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.mapper.AuthorManagerBookMapper;
import com.pacg.spring_endback.service.AuthorManagerBookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class AuthorManagerBookServiceImpl implements AuthorManagerBookService {
    @Autowired
    AuthorManagerBookMapper authorManagerBookMapper;
    @Override
    public List<Book> getBookByAuthor(String authorName) {
        return authorManagerBookMapper.getBookByAuthor(authorName);
    }
}
