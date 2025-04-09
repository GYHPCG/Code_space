package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class ArticleUpdate {
    private Integer bookId;
    private String chapter;
    private Integer chapterId;
    private Boolean status;
}
