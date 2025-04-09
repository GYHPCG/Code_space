package com.pacg.spring_endback.result.request;

import lombok.Data;

@Data
public class UserPageRequest extends BaseRequest{
    private String name;
    private Integer age;
    private String phoneNumber;
    private String address;
    private String sex;
}
