package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.Book;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface AuthorManagerBookMapper {

    List<Book> getBookByAuthor(String authorName);
}
