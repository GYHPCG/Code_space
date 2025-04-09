package gcp.Collection.student;

public class student implements Comparable<student> {
    private String id;
    private String  xuehao;
    private String name;
    private int score;


    public student() {
    }
    public student(student s) {
        id = s.getId();
        xuehao = s.getXuehao();
        name = s.getName();
        score = s.getScore();
    }
    public student(String id, String xuehao, String name, int score) {
        this.id = id;
        this.xuehao = xuehao;
        this.name = name;
        this.score = score;
    }

    /**
     * 获取
     * @return id
     */
    public String getId() {
        return id;
    }

    /**
     * 设置
     * @param id
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * 获取
     * @return xuehao
     */
    public String getXuehao() {
        return xuehao;
    }

    /**
     * 设置
     * @param xuehao
     */
    public void setXuehao(String xuehao) {
        this.xuehao = xuehao;
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
     * @return score
     */
    public int getScore() {
        return score;
    }

    /**
     * 设置
     * @param score
     */
    public void setScore(int score) {
        this.score = score;
    }

    public String toString() {
        return "student{id = " + id + ", xuehao = " + xuehao + ", name = " + name + ", score = " + score + "}";
    }

    @Override
    public int compareTo(student o) {
        return xuehao.compareTo(o.getXuehao());
    }
}
