package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.Book;

import java.util.List;

public interface AuthorManagerBookService {

    List<Book> getBookByAuthor(String authorName);
}
