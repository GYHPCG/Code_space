package com.pancg;

import com.pancg.mapper.UserMapper;
import com.pancg.pojo.User;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
class SpringbootMybitisApplicationTests {
    @Autowired
    private UserMapper userlist;

    @Test
    public void testListUser() {
        List<User> user =  userlist.list();
        user.stream().forEach(u ->{
            System.out.println(u);
        });

    }

}
