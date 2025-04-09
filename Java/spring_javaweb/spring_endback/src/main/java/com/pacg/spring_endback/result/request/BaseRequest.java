package com.pacg.spring_endback.result.request;

import lombok.Data;

@Data
public class BaseRequest {
    private Integer pageNumber = 1;
    private Integer pageSize = 10;
}
