package com.pacg.spring_endback.result.request;

import lombok.Data;

import javax.persistence.criteria.CriteriaBuilder;
import java.time.LocalDate;

@Data
public class BookPageRequest extends BaseRequest{

    private String name;
    private String author;
//    private String introduction;
    private String type;
    private Integer id;
//    private LocalDate createDate;
//    private LocalDate updateTime;
//    private String imgUrl;
//    private Boolean status;
}
