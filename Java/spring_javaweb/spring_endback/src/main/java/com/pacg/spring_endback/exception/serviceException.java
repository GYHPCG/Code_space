package com.pacg.spring_endback.exception;

public class serviceException extends RuntimeException {
    private String code;
    public serviceException(String msg) {
        super(msg);
    }
    public serviceException(String code , String msg) {
        super(msg);
        this.code = code;

    }

    public serviceException() {
    }

    /**
     * 获取
     * @return code
     */
    public String getCode() {
        return code;
    }

    /**
     * 设置
     * @param code
     */
    public void setCode(String code) {
        this.code = code;
    }

    public String toString() {
        return "serviceException{code = " + code + "}";
    }
}
