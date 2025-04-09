package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.Comment;

import java.math.BigDecimal;
import java.util.List;
public interface CommentService {
    List<Comment> findAllByBookId(Integer bookId);

    void save(Comment comment);

    List<Comment> getRateByBookId(Integer bookId);

    BigDecimal getPersonalRate(Integer userId, String userName, Integer bookId);

    void rate(Comment comment);
}
