package com.pacg.spring_endback.service.impl;

import com.pacg.spring_endback.entity.Comment;
import com.pacg.spring_endback.mapper.CommentMapper;
import com.pacg.spring_endback.service.CommentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.util.List;
@Service
public class CommentServiceImpl implements CommentService {
    @Autowired
    CommentMapper commentMapper;
    @Override
    public List<Comment> findAllByBookId(Integer bookId) {
        return commentMapper.findAllByBookId(bookId);
    }

    @Override
    public void save(Comment comment) {
      commentMapper.save(comment);
    }

    @Override
    public List<Comment> getRateByBookId(Integer bookId) {
        return  commentMapper.getRateByBookId(bookId);
    }

    @Override
    public BigDecimal getPersonalRate(Integer userId, String userName, Integer bookId) {
        return commentMapper.getPersonalRate(userId, userName, bookId);
    }

    @Override
    public void rate(Comment comment) {
        commentMapper.rate(comment);
    }
}
