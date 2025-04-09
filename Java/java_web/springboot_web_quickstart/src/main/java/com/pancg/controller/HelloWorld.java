package com.pancg.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloWorld {

    @RequestMapping("/hello")
    public String hello() {
        System.out.println("Hello, World~");
        return "Hello, World~";
    }
}
