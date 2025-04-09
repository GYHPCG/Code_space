package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.Comment;
import org.apache.ibatis.annotations.Mapper;

import java.math.BigDecimal;
import java.util.List;
@Mapper
public interface CommentMapper {

    List<Comment> findAllByBookId(Integer bookId);

    void save(Comment comment);

    List<Comment> getRateByBookId(Integer bookId);

    BigDecimal getPersonalRate(Integer userId, String userName, Integer bookId);

    void rate(Comment comment);
}
