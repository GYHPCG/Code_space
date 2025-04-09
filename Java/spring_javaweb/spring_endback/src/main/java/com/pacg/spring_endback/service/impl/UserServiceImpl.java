package com.pacg.spring_endback.service.impl;
import cn.hutool.core.util.RandomUtil;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.pacg.spring_endback.Utils.TokenUtils;
import com.pacg.spring_endback.entity.Admin;
import com.pacg.spring_endback.exception.serviceException;
import com.pacg.spring_endback.mapper.UserMapper;
import com.pacg.spring_endback.entity.User;
import com.pacg.spring_endback.result.DTO.LoginDTO;
import com.pacg.spring_endback.result.request.LoginRequest;
import com.pacg.spring_endback.result.request.UserPageRequest;
import com.pacg.spring_endback.service.UserService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.mail.javamail.MimeMessageHelper;
import org.springframework.stereotype.Service;

import javax.mail.MessagingException;
import javax.mail.internet.MimeMessage;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    UserMapper userMapper;
    @Autowired
    JavaMailSender javaMailSender;

    @Value("${spring.mail.username}")
    private String from;
    @Override
    public ArrayList<User> listUser() {
        return userMapper.listUser();
    }

    @Override
    public Object page(UserPageRequest userPageRequest) {
        PageHelper.startPage(userPageRequest.getPageNumber(), userPageRequest.getPageSize());
        List<User> users = userMapper.page(userPageRequest);
        return new PageInfo<>(users);
    }

    @Override
    public void addUser(User user) {
        userMapper.addUser(user);
    }

    @Override
    public void deleteUser(Integer id) {
        userMapper.deleteUser(id);
    }

    @Override
    public User getUser(Integer id) {
        return userMapper.getUser(id);
    }

    @Override
    public void updateInfo(User user) {
        userMapper.updateInfo(user);
    }

    @Override
    public LoginDTO login(LoginRequest user) throws serviceException {
        User userBypasswd = userMapper.getUserBypasswd(user);
        if (userBypasswd == null) {
            throw new serviceException("用户名或密码错误");
        }
        LoginDTO loginDTO = new LoginDTO();
        BeanUtils.copyProperties(userBypasswd, loginDTO);
        String token = TokenUtils.genToken(String.valueOf(userBypasswd.getId()), userBypasswd.getPasswd());
        loginDTO.setToken(token);
        return loginDTO;
    }

    @Override
    public void updatePass(String name, String passwd, String newPasswd) {
        userMapper.updatePasswd(name, passwd, newPasswd);
    }

    @Override
    public void register(LoginRequest user1) {
        User userDb = userMapper.getUserByName(user1);

        if (null != userDb) {
            throw new serviceException("用户名已存在");
        }

        User user = new User();
        user.setName(user1.getName());
        user.setPasswd(user1.getPasswd());
        user.setRole(user1.getRole());
        userMapper.addUser(user);
    }

    @Override
    public User getByEmail(String email, String code) {
        return userMapper.getByEmail(email, code);
    }

    @Override
    public void updateByName(User user) {
        userMapper.resetPasswd(user.getName(),user.getPasswd());
    }

    @Override
    public void sendEmailCode(String email) throws MessagingException {
        String code = RandomUtil.randomNumbers(4); // 随机一个 4位长度的验证码
        Date now = new Date();
        MimeMessage message = javaMailSender.createMimeMessage();
        MimeMessageHelper helper=new MimeMessageHelper(message);
        helper.setSubject("忘记密码验证");
        helper.setFrom(from);  // 发送人
        helper.setTo(email);
        helper.setSentDate(now);
        String context="<b>尊敬的用户：</b><br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;您好，您本次忘记密码的验证码是："+
                "<b color=\"'red'\">"  + code + "</b><br>"
                +"，有效期5分钟。请妥善保管，切勿泄露";
        helper.setText(context, true);
        javaMailSender.send(message);
        userMapper.sendCode(code, email);
    }
}
