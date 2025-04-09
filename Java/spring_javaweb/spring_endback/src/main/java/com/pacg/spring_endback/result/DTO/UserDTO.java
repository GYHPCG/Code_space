package com.pacg.spring_endback.result.DTO;

import lombok.Data;

@Data
public class UserDTO {
    private Integer id;
    private String username;
    private String email;
    private String code;
    private String password;
    private String nickname;
    private String avatarUrl;
    private String token;
    private String role;
}

