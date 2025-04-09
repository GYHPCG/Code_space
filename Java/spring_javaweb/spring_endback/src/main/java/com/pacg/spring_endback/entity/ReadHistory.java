package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class ReadHistory {
    private Integer bookId;
    private Integer chapterId;
    private Integer userId;
    private String role;
}
