package com.pacg.spring_endback.mapper;

import com.pacg.spring_endback.dao.ValidateDao;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ValidateDaoMapper {
    //邮箱验证重置密码
    int insert(ValidateDao validateDao);

    ValidateDao selectByToken(String token);

    List<ValidateDao> selectByEmail(String email);
}
