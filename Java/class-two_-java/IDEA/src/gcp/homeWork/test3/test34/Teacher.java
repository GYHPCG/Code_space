package gcp.homeWork.test3.test34;

public class Teacher extends Person{
    private String post;

    public Teacher() {
    }

    public Teacher(String id,String name,String post) {
        super(id,name);
        this.post = post;
    }

    /**
     * 获取
     * @return post
     */
    public String getPost() {
        return post;
    }

    /**
     * 设置
     * @param post
     */
    public void setPost(String post) {
        this.post = post;
    }

    public String toString() {
        return "Teacher{post = " + post + "}";
    }
}
