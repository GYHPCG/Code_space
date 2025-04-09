package com.pacg.spring_endback.controller;

import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.service.AuthorManagerBookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@CrossOrigin
@RequestMapping("/authorManager")
public class AuthorManagerBookController {
     @Autowired
    AuthorManagerBookService authorManagerBookService;

    @GetMapping("/book")
    public Result authorManagerBook(@RequestParam String authorName) {
        // 处理逻辑
        List<Book> bookList =  authorManagerBookService.getBookByAuthor(authorName);
        return Result.success(bookList);
    }
}
