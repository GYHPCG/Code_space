package gcp.homeWork.test3.test34;

public class Student extends Person{
    private String sno;

    public Student() {
    }

    public Student(String id,String name,String sno) {
        super(id,name);
        this.sno = sno;
    }

    /**
     * 获取
     * @return sno
     */
    public String getSno() {
        return sno;
    }

    /**
     * 设置
     * @param sno
     */
    public void setSno(String sno) {
        this.sno = sno;
    }

    public String toString() {
        return "Student{sno = " + sno + "}";
    }
}
