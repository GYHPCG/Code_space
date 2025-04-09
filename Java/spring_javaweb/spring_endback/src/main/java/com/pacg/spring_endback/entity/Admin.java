package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class Admin extends Base {
   private Integer id;
   private String name;
   private String passwd = "";
   private Integer age;
   private String phoneNumber;
   private String address;
   private String sex;
   private String email;
   private Boolean status = true;
   private String role;
}
