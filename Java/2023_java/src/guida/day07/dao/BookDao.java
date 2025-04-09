package guida.day07.dao;

import guida.day07.pojo.Book;

import java.sql.SQLException;
import java.util.List;

public interface BookDao {
    List<Book> getBookList(String bookName, String author, String type, String desc ) throws SQLException;
}
