package com.pacg.spring_endback.service;

import com.pacg.spring_endback.dao.ValidateDao;
import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.mapper.ValidateDaoMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import javax.mail.internet.MimeMessage;
import java.util.Date;
import java.util.List;
import java.util.Optional;

@Service
public class ValidateService{

    @Autowired
    private JavaMailSender javaMailSender;

    @Autowired
    private ValidateDaoMapper validateDaoMapper;


}


