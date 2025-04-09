package com.pacg.spring_endback.entity;

import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
@Data
public class Book {
   private Integer id;
   private String name;
   private String author;
   private String introduction;
   private String type;
   @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
   private LocalDate createDate;
   @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
   private LocalDate updateTime;
   private String imgUrl;
   private Boolean status = true;
   private Boolean end = false;  //书籍是否完结
   private BigDecimal rate;  //书籍的总评分


}
