package com.pacg.spring_endback.service.impl;

import com.pacg.spring_endback.entity.*;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.ArticleMapper;
import com.pacg.spring_endback.service.ArticleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ArticleServiceImpl implements ArticleService {
    @Autowired
    ArticleMapper articleMapper;
    @Override
    public Article getContent(Integer bookId) {
        List<ArticleContent> contents = articleMapper.getContent(bookId);

        if (contents.isEmpty()) {
            throw new serviceException("该书籍暂时还没有任何内容");
        }

        Article article = new Article();
        article.setBookId(bookId);
        article.setChapters(contents);

        return article;
    }

    @Override
    public void enable(ArticleUpdate articleUpdate) {
        articleMapper.enable(articleUpdate);
    }

    @Override
    public void delChapter(ArticleUpdate articleUpdate) {
        articleMapper.delChapter(articleUpdate);
    }

    @Override
    public EditChapter getBookNameAndContent(ArticleUpdate articleUpdate) {
        return articleMapper.getBookNameAndContent(articleUpdate);
    }

    @Override
    public void edit(EditChapter editChapter) {
        articleMapper.edit(editChapter);
    }

    @Override
    public void publishChapter(EditChapter editChapter) {
        articleMapper.publishChapter(editChapter);
    }

    @Override
    public void newChapter(EditChapter editChapter) {
        articleMapper.newChapter(editChapter);
    }

    @Override
    public EditChapter getLatestChap(Integer bookId) {
        return articleMapper.getLatestChap(bookId);
    }

    @Override
    public void lastReadChapter(ReadHistory readHistory) {

        boolean isRead = articleMapper.isRead(readHistory);
        //如果没有读过这本书，则第一次阅读的时候先插入记录
        if (!isRead) {
            articleMapper.firstRead(readHistory);
        }
        //如果已经读过了，则更新为最后一次阅读的章节
        else {
            articleMapper.updateRead(readHistory);
        }
    }

    @Override
    public EditChapter getLastReadChapter(Integer userId, String role, Integer bookId) {
        ReadHistory readHistory = new ReadHistory();
        readHistory.setBookId(bookId);
        readHistory.setRole(role);
        readHistory.setUserId(userId);
        boolean isRead = articleMapper.isRead(readHistory);

        //如果没有读过，返回第一章
        if (!isRead) {
            return articleMapper.getFirstChapter(userId, role, bookId);
        }
        //如果读过，则返回最后一次阅读的章节
        else {
            return articleMapper.getLastReadChapter(userId, role, bookId);
        }

    }

    @Override
    public Article userGetContent(Integer bookId) {
        List<ArticleContent> contents = articleMapper.userGetContent(bookId);
        if (contents.isEmpty()) {
            throw new serviceException("该书籍暂时还没有任何内容");
        }
        Article article = new Article();
        article.setBookId(bookId);
        article.setChapters(contents);
        return article;
    }
}
