package com.pacg.spring_endback.entity;

import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;

import java.time.LocalDate;

@Data
public class Author {
    private Integer id;
    private String penName;
    private String passwd = "author123"; // 默认密码
    private String name;
    private String introduce;
    private String phone;
    private Integer bookId;
    private String address;
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private LocalDate joinTime;
    private String role = "作家";
    private Boolean status = true;
    private String qq;
    private String avatar;
}
