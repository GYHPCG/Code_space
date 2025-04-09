package com.pacg.spring_endback.result.request;

import lombok.Data;

@Data
public class LoginRequest {
    private String name;
    private String passwd;
    private String confirmPass;
    private String role;
}
