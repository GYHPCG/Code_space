package gcp.Collection.student;

import java.util.ArrayList;
import java.util.Scanner;

public class Test {
    //查询学生信息
     public static void getInfoXuehao(ArrayList<student> st,String s) {
        for (int i = 0; i < st.size(); i++) {
            if (st.get(i).getXuehao().compareTo(s) == 0) {
                System.out.println(st.get(i).toString());
                return ;
            }
        }
         System.out.println("没有该学生");
        return ;
    }

    public static void getInfoId(ArrayList<student> st, String s) {
        for (int i = 0; i < st.size(); i++) {
            if (st.get(i).getId().compareTo(s) == 0) {
                System.out.println(st.get(i).toString());
                return ;
            }
        }
        System.out.println("没有这个人");
        return ;
    }
    public static void InsertStudent(ArrayList<student> st, student s) {
         int i = 0;
         while(st.get(i).getXuehao().compareTo(s.getXuehao()) < 0) {
             i++;
         }
         st.add(i,s);
        System.out.println(st);
    }
    //delete
    public static student idDelete(ArrayList<student>st, String s) {
        for (int i = 0; i < st.size(); i++) {
            if (st.get(i).getId().compareTo(s) == 0) {
                student stu = new student(st.get(i));
                st.remove(i);
                return stu;
            }
        }
        System.out.println("没有身份证是这个id的学生");
        return null;
    }
    public static student XuehaoDelete(ArrayList<student>st, String s) {
        for (int i = 0; i < st.size(); i++) {
            if (st.get(i).getId().compareTo(s) == 0) {
                student stu = new student(st.get(i));
                st.remove(i);
                return stu;
            }
        }
        System.out.println("没有学号是这个学号的学生");
        return null;
    }
    public static void creatArr(ArrayList<student> st) {

        final int n = 4;
        System.out.println("输入"+n+"个学生的id,xuehao,name,score");
        Scanner sc = new Scanner(System.in);
        String id;
        String xeuhao;
        String name;
        int score;
         for (int i = 0; i < n;++i) {
             id = sc.next();
             xeuhao = sc.next();
             name = sc.next();
             score = sc.nextInt();
             student st1 = new student(id,xeuhao,name,score);
             st.add(st1);

         }
         //sc.close();
//        student st1 = new student("52262220010917","2100770217","张三",99);
//        student st2 = new student("52262220020713","2100770203","李四",98);
//        student st3 = new student("52262220010928","2100770100","王五",80);
//        student st4 = new student("52262220030530","2100770098","刘二",45);
//        st.add(st1);
//        st.add(st2);

//        st.add(st3);
//        st.add(st4);
    }

    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
        ArrayList<student> st = new ArrayList<>();
        //st.
        creatArr(st);
        //按照学号从小到达排序
        //lambda表达式
        st.sort(((o1, o2) -> o1.getXuehao().compareTo(o2.getXuehao())));
        System.out.println(st);
        //String s = "2100770098";
        String s;
        System.out.println("输入查询学生学号:");
        s = sc.next();
        //学号查找
        getInfoXuehao(st,s);
        //String id = "52262220030530";
        String id;
        //Arrays.sort()
        System.out.println("输入查询学生身份证:");
        id = sc.next();

        //身份证查找
        getInfoId(st,id);
        //按照成绩从小到大排序
        st.sort(((o1,o2)->o1.getScore() - o2.getScore()));
        System.out.println(st);
        //插入学生，按学号从小到大排序输出
        System.out.println("请输入要插入学生的id,xuehao,name,score:");
        student stu = new student();
        stu.setId(sc.next());
        stu.setXuehao(sc.next());
        stu.setName(sc.next());
        stu.setScore(sc.nextInt());
        //student stu = new student("52262220070912","2100770189","李华",100);
        //插入学生
        InsertStudent(st,stu);
        //删除学生
        System.out.println("请输入要删除的学生学号：");
        String deXuehao = sc.next();
        XuehaoDelete(st,deXuehao);
        //String deIdSt = "52262220070912";
        System.out.println("请输入要删除学生的id:");
        String deIdSt = sc.next();
        idDelete(st,deIdSt);

        System.out.println(st);

    }

    //
}
