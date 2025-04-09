package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.AddBookToShelf;
import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.result.request.BookPageRequest;
import org.apache.ibatis.annotations.Mapper;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

@Mapper
public interface BookMapper {
    ArrayList<Book> listBook();
    List<Book> page(BookPageRequest bookPageRequest);

    void addBook(Book book);

    void deleteBook(Integer id);

    Book getBook(Integer id);

    void updateInfo(Book book);

    List<Book> search(BookPageRequest bookPageRequest);

    List<Book> getBookshelf(BookPageRequest bookPageRequest);

    void addToList(AddBookToShelf addBookToShelf);

    void delFromShelf(AddBookToShelf delBookFromShelf);

    boolean isExitsInShelf(AddBookToShelf addBookToShelf);

    Book getBookByAuthorAndName(String author, String name);

    void endBook(Integer id);

    List<Book> pageByRate(BookPageRequest bookPageRequest);

    List<Book> getBookPubShelf(BookPageRequest bookPageRequest);

    void setTotalRate(Integer bookId, BigDecimal rate);
}
