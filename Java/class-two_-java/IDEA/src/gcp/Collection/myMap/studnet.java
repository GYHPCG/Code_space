package gcp.Collection.myMap;

import java.util.Objects;

public class studnet implements Comparable<studnet>{
    private String name;
    private  int age;

    public studnet() {
    }

    public studnet(String name, int age) {
        this.name = name;
        this.age = age;
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

    public String toString() {
        return "studnet{name = " + name + ", age = " + age + "}";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        studnet studnet = (studnet) o;
        return age == studnet.age && Objects.equals(name, studnet.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    @Override
    public int compareTo(studnet o) {
        int i = 0;
        i = this.getAge() - o.getAge();
        i = i == 0?this.getName().compareTo(o.getName()):i;
        return i;
    }
}
