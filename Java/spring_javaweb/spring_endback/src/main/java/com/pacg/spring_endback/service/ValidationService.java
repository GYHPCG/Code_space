package com.pacg.spring_endback.service;

import cn.hutool.core.date.DateTime;

public interface ValidationService {
    public void saveCode(String email, String code, Integer type, DateTime expireDate);
}
