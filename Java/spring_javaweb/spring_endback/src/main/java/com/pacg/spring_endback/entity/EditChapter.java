package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class EditChapter {
    private String name;
    private Integer articleId;
    private Integer bookId;
    private String chapter;
    private Integer chapterId;
    private String content;
    private String lastChapter;
    private Boolean end;
    private Boolean status;
}
