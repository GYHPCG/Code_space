package protype;

public class Resume implements Cloneable{
    private String name;
    private String sex;
    private int age;
    private String company;

    public Resume() {
    }

    public Resume(String name, String sex, int age, String company) {
        this.name = name;
        this.sex = sex;
        this.age = age;
        this.company = company;
    }

    /**
     * 获取
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * 设置
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 获取
     * @return sex
     */
    public String getSex() {
        return sex;
    }

    /**
     * 设置
     * @param sex
     */
    public void setSex(String sex) {
        this.sex = sex;
    }

    /**
     * 获取
     * @return age
     */
    public int getAge() {
        return age;
    }

    /**
     * 设置
     * @param age
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * 获取
     * @return company
     */
    public String getCompany() {
        return company;
    }

    /**
     * 设置
     * @param company
     */
    public void setCompany(String company) {
        this.company = company;
    }

    public String toString() {
        return "Resume{name = " + name + ", sex = " + sex + ", age = " + age + ", company = " + company + "}";
    }
    public void setWork(String com, int age) {
        this.company = com;
        this.age = age;
    }
    public Resume clone() throws CloneNotSupportedException {
        Resume obj = null;
        obj = (Resume)super.clone();
        return obj;
    }
}
