package com.pacg.spring_endback.controller;

import com.pacg.spring_endback.entity.Article;
import com.pacg.spring_endback.entity.ArticleUpdate;
import com.pacg.spring_endback.entity.EditChapter;
import com.pacg.spring_endback.entity.ReadHistory;
import com.pacg.spring_endback.result.Result;
import com.pacg.spring_endback.service.ArticleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/write")
public class ArticleController {
    @Autowired
    ArticleService articleService;

    //作者获取章节内容
    @GetMapping("/getContent/{bookId}")
    public Result getContent(@PathVariable Integer bookId) {
        Article bookContent =  articleService.getContent(bookId);
        return Result.success(bookContent);
    }
    //用户获取章节内容，如果章节没有发布出来，则用户看不到
    @GetMapping("/userGetContent/{bookId}")
    public Result userGetContent(@PathVariable Integer bookId) {
        return Result.success(articleService.userGetContent(bookId));
    }
    @PutMapping("/enable")
    public Result enable(@RequestBody ArticleUpdate articleUpdate) {
        articleService.enable(articleUpdate);
        return Result.success();
    }
   @PutMapping("/delChapter")
    public Result delChapter(@RequestBody ArticleUpdate articleUpdate) {
        articleService.delChapter(articleUpdate);
        return Result.success();
   }
   @PostMapping("/getBookNameAndContent")
    public Result getBookNameAndContent(@RequestBody ArticleUpdate articleUpdate) {
        return Result.success(articleService.getBookNameAndContent(articleUpdate));
   }
   @PostMapping("/edit")
    public Result edit(@RequestBody EditChapter editChapter) {
        articleService.edit(editChapter);
        return Result.success();
   }
   @PostMapping("/publish")
    public Result publishChapter(@RequestBody EditChapter editChapter) {
        articleService.publishChapter(editChapter);
        return Result.success();
   }
   @PostMapping("/newChapter")
    public Result newChapter(@RequestBody EditChapter editChapter) {
        articleService.newChapter(editChapter);
        return Result.success();
   }
   //获取最新章节
   @GetMapping("/getLatestChap/{bookId}")
    public Result latestChap(@PathVariable Integer bookId) {
        return Result.success(articleService.getLatestChap(bookId));
   }
   // 所谓阅读记录，即更新最后一次阅读的章节
   @PostMapping("/readHistory")
    public Result lastReadChapter(@RequestBody ReadHistory readHistory) {
        articleService.lastReadChapter(readHistory);
        return Result.success();
   }
   // 获取最后阅读的章节
    @GetMapping("/getLastReadChapter")
    public Result getLastReadChapter(@RequestParam("userId") Integer userId, @RequestParam("role") String role, @RequestParam("bookId") Integer bookId) {
        EditChapter editChapter =  articleService.getLastReadChapter(userId, role, bookId);
        return Result.success(editChapter);
    }

}
