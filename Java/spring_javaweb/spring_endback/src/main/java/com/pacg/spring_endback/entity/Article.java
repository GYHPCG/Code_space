package com.pacg.spring_endback.entity;

import lombok.Data;

import java.util.List;

@Data
public class Article {
    private Integer articleId;
    private Integer bookId;
    List<ArticleContent> chapters;
    private Boolean end = false;
}
