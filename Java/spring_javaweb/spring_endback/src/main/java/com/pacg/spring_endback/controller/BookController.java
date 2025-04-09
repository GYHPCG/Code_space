package com.pacg.spring_endback.controller;

import com.pacg.spring_endback.entity.AddBookToShelf;
import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.result.request.BookPageRequest;
import com.pacg.spring_endback.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@CrossOrigin
@RequestMapping("/book")
public class BookController {
    @Autowired
    BookService bookService;

    @GetMapping("/list")
    public Result bookArrayList() {
        return Result.success(bookService.listBook());
    }
    //分页模糊查询
    @GetMapping("/page")
    public Result page(BookPageRequest bookPageRequest) {
        return Result.success(bookService.page(bookPageRequest));
    }
    //按评分获取书籍推荐
    @GetMapping("/pageByRate")
    public Result pageByRate(BookPageRequest bookPageRequest) {
        return Result.success(bookService.pageByRate(bookPageRequest));
    }
    @GetMapping("/bookshelf")
    public Result bookshelf(BookPageRequest bookPageRequest) {
        return Result.success(bookService.bookshelf(bookPageRequest));
    }

    @GetMapping("/bookPubShelf")
    public Result bookPubShelf(BookPageRequest bookPageRequest) {
        return Result.success(bookService.bookPubShelf(bookPageRequest));
    }

    @GetMapping("/search")
    public Result search(BookPageRequest bookPageRequest) {

        return Result.success(bookService.search(bookPageRequest));
    }
    //添加书籍
    @PostMapping("/addBook")
    public Result addBook(@RequestBody Book book) {
        bookService.addBook(book);
        String author = book.getAuthor();
        String name = book.getName();
        Book getBook = bookService.getBookByAuthorAndName(author,name);
        return Result.success(getBook);
    }
    //获取书籍信息
    @GetMapping("/getInfo/{id}")
    public Result getInfo(@PathVariable Integer id) {
        Book book = bookService.getBook(id);
        return Result.success(book);
    }
    //修改用户
    @PutMapping("/updateInfo")
    public Result updateInfo(@RequestBody Book book) {
        bookService.updateInfo(book);
        return Result.success();
    }
    //删除书籍
    @DeleteMapping("/del/{id}")
    public Result deleteBook(@PathVariable Integer id) {
        bookService.deleteBook(id);
        return Result.success();
    }
    @PostMapping("/addToShelf")
    public Result addToShelf(@RequestBody AddBookToShelf addBookToShelf) {
        bookService.addBookToList(addBookToShelf);
        return Result.success();
    }
    @PostMapping("/delFromShelf")
    public Result delFromShelf(@RequestBody AddBookToShelf delBookFromShelf) {
        bookService.delBookFromShelf(delBookFromShelf);
        return Result.success();
    }
    @PutMapping("/end/{id}")
    public Result endBook(@PathVariable Integer id) {
        bookService.endBook(id);
        return Result.success();
    }
}
