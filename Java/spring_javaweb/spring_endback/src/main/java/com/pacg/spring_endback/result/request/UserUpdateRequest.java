package com.pacg.spring_endback.result.request;

import lombok.Data;

@Data
public class UserUpdateRequest {
    private String name;
    private String passwd;
    private String newPasswd;
}
