package guida.day07.service;

import guida.day07.pojo.Book;

import java.util.List;

public interface BookService {

    List<Book> getBookList(String bookName, String author, String type, String desc);
}
