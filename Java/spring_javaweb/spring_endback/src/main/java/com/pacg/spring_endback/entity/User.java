package com.pacg.spring_endback.entity;

import lombok.Data;

@Data
public class User extends Base {
   private Integer id;
   private String name;
   private String passwd = "666";
   private Integer age;
   private String phoneNumber;
   private String address;
   private String sex;
   private String email;
   private String code;
   private Boolean status = true;
   private String role;
   private String avatar;
}
