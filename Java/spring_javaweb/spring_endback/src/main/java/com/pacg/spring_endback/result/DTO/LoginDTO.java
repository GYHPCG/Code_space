package com.pacg.spring_endback.result.DTO;

import lombok.Data;

@Data
public class LoginDTO {
    private Integer id;
    private String name;
    private String phoneNumber;
    private String email;
    private String role;
    private String avatar;
    private String token;
    private Boolean status;
}
