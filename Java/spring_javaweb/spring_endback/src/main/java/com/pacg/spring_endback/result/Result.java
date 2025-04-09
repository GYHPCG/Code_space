package com.pacg.spring_endback.result;

import lombok.Data;

@Data
//包装结果对象
public class Result {
    private static final String SUCCESS_CODE = "200";
    private static final String ERROR_CODE = "-1";

    private String code;
    private Object data;
    private String message;

    public static Result success() {
        Result result = new Result();
        result.setCode(SUCCESS_CODE);
        return result;
    }

    public static Result success(Object data) {
        Result result = new Result();
        result.setData(data);
        result.setCode(SUCCESS_CODE);
        return result;
    }

    public static Result success(String message) {
        Result result = new Result();
        result.setCode(SUCCESS_CODE);
        result.setMessage(message);
        return result;
    }
    public static Result error(String msg) {
        Result result = new Result();
        result.setCode(ERROR_CODE);
        result.setMessage(msg);
        return result;
    }


    public static Result error(String code, String message) {
        Result result = new Result();
        result.setCode(code);
        result.setMessage(message);
        return result;
    }
}
