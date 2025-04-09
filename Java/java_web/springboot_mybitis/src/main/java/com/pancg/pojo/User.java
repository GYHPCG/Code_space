package com.pancg.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;
@Data
@NoArgsConstructor
@AllArgsConstructor
public class User {
    private String Sno;
    private String Sname;
    private String Ssex;
    private Integer Sage;
    private Date Birthday;
    private String Deptment;


//    public User() {
//    }
//
//    public User(String Sno, String Sname, String Ssex, Integer Sage, Date Birthday, String Deptment) {
//        this.Sno = Sno;
//        this.Sname = Sname;
//        this.Ssex = Ssex;
//        this.Sage = Sage;
//        this.Birthday = Birthday;
//        this.Deptment = Deptment;
//    }
//
//    public User(String Sno, String Sname, String Ssex, Integer Sage, String Deptment) {
//        this.Sno = Sno;
//        this.Sname = Sname;
//        this.Ssex = Ssex;
//        this.Sage = Sage;
//        this.Deptment = Deptment;
//    }
//
//    /**
//     * 获取
//     * @return Sno
//     */
//    public String getSno() {
//        return Sno;
//    }
//
//    /**
//     * 设置
//     * @param Sno
//     */
//    public void setSno(String Sno) {
//        this.Sno = Sno;
//    }
//
//    /**
//     * 获取
//     * @return Sname
//     */
//    public String getSname() {
//        return Sname;
//    }
//
//    /**
//     * 设置
//     * @param Sname
//     */
//    public void setSname(String Sname) {
//        this.Sname = Sname;
//    }
//
//    /**
//     * 获取
//     * @return Ssex
//     */
//    public String getSsex() {
//        return Ssex;
//    }
//
//    /**
//     * 设置
//     * @param Ssex
//     */
//    public void setSsex(String Ssex) {
//        this.Ssex = Ssex;
//    }
//
//    /**
//     * 获取
//     * @return Sage
//     */
//    public Integer getSage() {
//        return Sage;
//    }
//
//    /**
//     * 设置
//     * @param Sage
//     */
//    public void setSage(Integer Sage) {
//        this.Sage = Sage;
//    }
//
//    /**
//     * 获取
//     * @return Birthday
//     */
//    public Date getBirthday() {
//        return Birthday;
//    }
//
//    /**
//     * 设置
//     * @param Birthday
//     */
//    public void setBirthday(Date Birthday) {
//        this.Birthday = Birthday;
//    }
//
//    /**
//     * 获取
//     * @return Deptment
//     */
//    public String getDeptment() {
//        return Deptment;
//    }
//
//    /**
//     * 设置
//     * @param Deptment
//     */
//    public void setDeptment(String Deptment) {
//        this.Deptment = Deptment;
//    }
//
//    public String toString() {
//        return "User{Sno = " + Sno + ", Sname = " + Sname + ", Ssex = " + Ssex + ", Sage = " + Sage + ", Birthday = " + Birthday + ", Deptment = " + Deptment + "}";
//    }
}
