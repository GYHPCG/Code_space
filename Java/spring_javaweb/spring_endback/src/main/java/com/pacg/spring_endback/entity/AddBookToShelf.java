package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class AddBookToShelf {
    private Integer userId;
    private Integer bookId;
}
