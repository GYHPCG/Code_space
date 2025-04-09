package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.LoginRequest;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface LoginMapper {
    LoginDTO getUserByName(LoginRequest user);

    LoginDTO getByName(String userName);
}
