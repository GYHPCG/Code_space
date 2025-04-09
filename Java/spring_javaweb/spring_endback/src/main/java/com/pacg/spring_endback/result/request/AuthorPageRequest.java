package com.pacg.spring_endback.result.request;

import lombok.Data;

@Data
public class AuthorPageRequest extends BaseRequest{
    private String penName;
    private Integer name;
    private String introduce;
    private String phone;
    private String address;
}
