package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.entity.*;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ArticleMapper {
    List<ArticleContent> getContent(Integer bookId);

    Integer getArticleId(Integer bookId);

    void enable(ArticleUpdate articleUpdate);

    void delChapter(ArticleUpdate articleUpdate);

    EditChapter getBookNameAndContent(ArticleUpdate articleUpdate);

    void edit(EditChapter editChapter);

    void publishChapter(EditChapter editChapter);

    void newChapter(EditChapter editChapter);

    EditChapter getLatestChap(Integer bookId);

    boolean isRead(ReadHistory readHistory);

    void firstRead(ReadHistory readHistory);

    void updateRead(ReadHistory readHistory);

    EditChapter getFirstChapter(Integer userId, String role, Integer bookId);

    EditChapter getLastReadChapter(Integer userId, String role, Integer bookId);

    List<ArticleContent> userGetContent(Integer bookId);
}
