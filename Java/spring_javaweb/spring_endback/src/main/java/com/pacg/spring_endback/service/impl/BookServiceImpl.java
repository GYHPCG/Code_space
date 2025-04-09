package com.pacg.spring_endback.service.impl;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.pacg.spring_endback.entity.AddBookToShelf;
import com.pacg.spring_endback.entity.Book;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.BookMapper;
import com.pacg.spring_endback.result.request.BookPageRequest;
import com.pacg.spring_endback.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

@Service
public class BookServiceImpl implements BookService {
    @Autowired
    BookMapper bookMapper;
    @Override
    public ArrayList<Book> listBook() {
        return bookMapper.listBook();
    }

    @Override
    public Object page(BookPageRequest bookPageRequest) {
        PageHelper.startPage(bookPageRequest.getPageNumber(), bookPageRequest.getPageSize());
        List<Book> books = bookMapper.page(bookPageRequest);
        return new PageInfo<>(books);
    }

    @Override
    public Object search(BookPageRequest bookPageRequest) {
        PageHelper.startPage(bookPageRequest.getPageNumber(), bookPageRequest.getPageSize());
        List<Book> books = bookMapper.search(bookPageRequest);
        return new PageInfo<>(books);
    }

    @Override
    public void addBook(Book book) {
        bookMapper.addBook(book);
    }

    @Override
    public void deleteBook(Integer id) {
        bookMapper.deleteBook(id);
    }

    @Override
    public Book getBook(Integer id) {
        return bookMapper.getBook(id);
    }

    @Override
    public void updateInfo(Book book) {
        bookMapper.updateInfo(book);
    }

    @Override
    public Object bookshelf(BookPageRequest bookPageRequest) {
        PageHelper.startPage(bookPageRequest.getPageNumber(), bookPageRequest.getPageSize());
        List<Book> books = bookMapper.getBookshelf(bookPageRequest);
        return new PageInfo<>(books);
    }

    @Override
    public void addBookToList(AddBookToShelf addBookToShelf) {
        boolean isExits = bookMapper.isExitsInShelf(addBookToShelf);
        if (!isExits) {
            bookMapper.addToList(addBookToShelf);
        }
        else {
            throw new serviceException("400", "书籍已在书架中，不可重复添加");
        }

    }

    @Override
    public void delBookFromShelf(AddBookToShelf delBookFromShelf) {
        bookMapper.delFromShelf(delBookFromShelf);
    }

    @Override
    public Book getBookByAuthorAndName(String author, String name) {
        return bookMapper.getBookByAuthorAndName(author, name);
    }

    @Override
    public void endBook(Integer id) {
        bookMapper.endBook(id);
    }

    @Override
    public Object pageByRate(BookPageRequest bookPageRequest) {
        PageHelper.startPage(bookPageRequest.getPageNumber(), bookPageRequest.getPageSize());
        List<Book> books = bookMapper.pageByRate(bookPageRequest);
        return new PageInfo<>(books);
    }

    @Override
    public Object bookPubShelf(BookPageRequest bookPageRequest) {
        PageHelper.startPage(bookPageRequest.getPageNumber(), bookPageRequest.getPageSize());
        List<Book> books = bookMapper.getBookPubShelf(bookPageRequest);
        return new PageInfo<>(books);
    }

    @Override
    public void totalRate(Integer bookId, Object rate) {
        bookMapper.setTotalRate(bookId, (BigDecimal) rate );
    }

}
