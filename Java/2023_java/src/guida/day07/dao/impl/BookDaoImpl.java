/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-10-15 14:08:30
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-11-11 18:30:15
 */
package guida.day07.dao.impl;
import guida.day06.C3P0Utils;
import guida.day07.dao.BookDao;
import guida.day07.pojo.Book;
import org.apache.commons.dbutils.BasicRowProcessor;
import org.apache.commons.dbutils.GenerousBeanProcessor;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class BookDaoImpl implements BookDao {
    @Override
    public List<Book> getBookList(String bookName, String author, String type, String desc) {
        QueryRunner queryRunner = new QueryRunner(C3P0Utils.getDataSource());
        List<Book> books = new ArrayList<>();
        List<String> params = new ArrayList<>();
        String sql = "select * from book where 1 = 1";

        if (!"".equals(bookName) && null != bookName) {
            sql += " and book_name like concat('%', ?, '%')";
            params.add(bookName);
        }
        if (!"".equals(author) && null != author) {
            sql += " and author = ?";
            params.add(author);
        }
        if (!"".equals(type) && null != type) {
            sql += " and type = ?";
            params.add(type);
        }
        if (!"".equals(desc) && null != desc) {
            sql += " and description like concat('%', ?, '%')";
            params.add(desc);
        }

            try {
                GenerousBeanProcessor beanProcessor = new GenerousBeanProcessor();
                BasicRowProcessor basicRowProcessor = new BasicRowProcessor(beanProcessor);
                books = queryRunner.query(sql, new BeanListHandler<Book>(Book.class, basicRowProcessor), params.toArray());
            } catch (SQLException e) {
                e.printStackTrace();
            }
            return books;
        }
    }