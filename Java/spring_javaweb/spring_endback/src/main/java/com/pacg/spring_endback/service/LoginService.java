package com.pacg.spring_endback.service;

import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.LoginRequest;

public interface LoginService {
    LoginDTO login(LoginRequest user) throws serviceException;

    LoginDTO getUserByName(String userName);
}
