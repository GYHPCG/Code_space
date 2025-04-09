package com.pacg.spring_endback.service;

import com.pacg.spring_endback.entity.Article;
import com.pacg.spring_endback.entity.ArticleUpdate;
import com.pacg.spring_endback.entity.EditChapter;
import com.pacg.spring_endback.entity.ReadHistory;

public interface ArticleService {

    Article getContent(Integer bookId);

    void enable(ArticleUpdate articleUpdate);

    void delChapter(ArticleUpdate articleUpdate);

    EditChapter getBookNameAndContent(ArticleUpdate articleUpdate);

    void edit(EditChapter editChapter);

    void publishChapter(EditChapter editChapter);

    void newChapter(EditChapter editChapter);

    EditChapter getLatestChap(Integer bookId);

    void lastReadChapter(ReadHistory readHistory);

    EditChapter getLastReadChapter(Integer userId, String role, Integer bookId);

    Article userGetContent(Integer bookId);
}
