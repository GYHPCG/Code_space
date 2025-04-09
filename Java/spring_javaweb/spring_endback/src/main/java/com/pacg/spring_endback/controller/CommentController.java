package com.pacg.spring_endback.controller;

import com.pacg.spring_endback.entity.Comment;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.service.BookService;
import com.pacg.spring_endback.service.CommentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/comment")
public class CommentController {
   @Autowired
    CommentService commentService;
   @Autowired
    BookService bookService;

   private BigDecimal personalScore;
   //评论
   @PostMapping
    public Result save(@RequestBody Comment comment) {
       comment.setCommentTime(LocalDateTime.now());
       commentService.save(comment);
       return Result.success();
   }
   //评分
   @PostMapping("/rate")
    public Result rate(@RequestBody Comment comment) {
        comment.setUpdateTime(LocalDateTime.now());
        BigDecimal rated =  commentService.getPersonalRate(comment.getUserId(), comment.getUserName(),comment.getBookId());
        // 如果没有评分过，则插入评分，否则更新评分
       System.out.println("rate: " + rated);
       if (rated == null) {
           commentService.save(comment);
       }
       else {
           commentService.rate(comment);
       }
        return Result.success();
    }
    //获取书籍的评论
   @GetMapping
    public Result list(@RequestParam Integer bookId) {
       Map<String, Object> map = new HashMap<>();
       List<Comment> comments =  commentService.findAllByBookId(bookId);
       List<Comment> commentList = comments.stream().filter(comment -> comment.getRate() != null).collect(Collectors.toList());
       commentList.stream().map(Comment::getRate).reduce(BigDecimal::add).ifPresent(res ->
       {map.put("rate", res.divide(BigDecimal.valueOf(commentList.size()), 1, RoundingMode.HALF_UP)); });

       map.put("comments", comments);

       //多级评论实现
       List<Comment> rootComments = comments.stream().filter(comment -> comment.getPid() == null).collect(Collectors.toList());
       for (Comment rootComment: rootComments) {
           rootComment.setChildren(comments.stream().filter(comment -> rootComment.getId().equals(comment.getPid())).collect(Collectors.toList()));
       }
       map.put("comments", rootComments);
       return Result.success(map);
   }
   //获取书籍的总评分
   @GetMapping("/rate")
    public Result getRate(@RequestParam Integer bookId) {
       Map<String, Object> map = new HashMap<>();
       List<Comment> comments =  commentService.getRateByBookId(bookId);
       List<Comment> commentList = comments.stream().filter(comment -> comment.getRate() != null).collect(Collectors.toList());
       commentList.stream().map(Comment::getRate).reduce(BigDecimal::add).ifPresent(res ->
       {map.put("rate", res.divide(BigDecimal.valueOf(commentList.size()), 1, RoundingMode.HALF_UP)); });
        // 更新书籍总评分
       bookService.totalRate(bookId, map.get("rate"));
       return Result.success(map);
   }
   @PostMapping("/personal_rate")
  public Result getPersonalRate(@RequestBody Comment comment) {
       BigDecimal rated = commentService.getPersonalRate(comment.getUserId(), comment.getUserName(),comment.getBookId());
       return Result.success(rated);
   }

}
