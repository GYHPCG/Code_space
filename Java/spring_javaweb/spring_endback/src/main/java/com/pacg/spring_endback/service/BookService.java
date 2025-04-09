package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.AddBookToShelf;
import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.result.request.BookPageRequest;

import java.util.ArrayList;

public interface BookService {
    ArrayList<Book> listBook();

    Object page(BookPageRequest bookPageRequest);

    //搜索书籍
    Object search(BookPageRequest bookPageRequest);

    void addBook(Book book);

    void deleteBook(Integer id);

    Book getBook(Integer id);

    void updateInfo(Book book);

    Object bookshelf(BookPageRequest bookPageRequest);

    void addBookToList(AddBookToShelf addBookToShelf);

    void delBookFromShelf(AddBookToShelf delBookFromShelf);

    Book getBookByAuthorAndName(String author, String name);

    void endBook(Integer id);

    Object pageByRate(BookPageRequest bookPageRequest);

    Object bookPubShelf(BookPageRequest bookPageRequest);

    void totalRate(Integer bookId, Object rate);
}
