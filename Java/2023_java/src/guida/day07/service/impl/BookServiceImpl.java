package guida.day07.service.impl;

import guida.day07.dao.impl.BookDaoImpl;
import guida.day07.pojo.Book;
import guida.day07.service.BookService;

import java.util.List;

public class BookServiceImpl implements BookService {


    @Override
    public List<Book> getBookList(String bookName, String author, String type, String desc) {
        return new BookDaoImpl().getBookList(bookName,author, type, desc);
    }
}
