package proxy1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Student {
    private String sno;
    private String sname;

    public Student(String sno, String sname) {
        this.sno = sno;
        this.sname = sname;
    }

    public String getSno() {
        return sno;
    }

    public void setSno(String sno) {
        this.sno = sno;
    }
}

interface VoteManagerInterface {
    void addStudent(Student s);

    void vote(Student voter, Student select);

    int getVoteNum(Student s);
}

class VoteManager implements VoteManagerInterface {
    private HashMap<String, Integer> map = new HashMap<String, Integer>();

    @Override
    public void addStudent(Student s) {
        map.put(s.getSno(), 0);
    }

    @Override
    public void vote(Student voter, Student select) {
        if (map.containsKey(select.getSno())) {
            Integer v = map.get(select.getSno());
            map.put(select.getSno(), v + 1);
        } else {
            map.put(select.getSno(), 0);
        }
    }

    @Override
    public int getVoteNum(Student s) {
        if (map.containsKey(s.getSno())) {
            return map.get(s.getSno());
        }
        return 0;
    }
}

class VoteManagerProxy implements VoteManagerInterface {

    private VoteManager vt;
    private HashMap<String, String> hm = new HashMap<String, String>();

    public VoteManagerProxy(VoteManager vt) {
        this.vt = vt;
    }

    @Override
    public void addStudent(Student s) {
        vt.addStudent(s);
    }

    @Override
    public void vote(Student voter, Student select) {
        if (voter.equals(select)) return;
        else {
            boolean tmp = false;
            for (Map.Entry entry: hm.entrySet()) {
                if (voter.getSno().equals(entry.getKey()) && select.getSno().equals(entry.getValue())) {
                    tmp = true;
                }
            }
            if (tmp) return;
            else {
                hm.put(voter.getSno(),select.getSno());
                vt.vote(voter, select);
            }
        }
    }

    @Override
    public int getVoteNum(Student s) {
        return vt.getVoteNum(s);
    }
}

public class Main {
    public static void main(String[] args) {

        Student s1 = new Student("001", "张三");

        Student s2 = new Student("002", "李四");

        Student s3 = new Student("003", "王五");


        VoteManagerInterface v = new VoteManagerProxy(new VoteManager());

        v.addStudent(s1);
        v.addStudent(s2);
        v.addStudent(s3);
        v.vote(s1, s1);
        v.vote(s1, s2);
        v.vote(s1, s2);
        v.vote(s1, s3);
        v.vote(s2, s1);
        v.vote(s3, s2);
        v.vote(s3, s1);
        v.vote(s3, s3);

        System.out.println(v.getVoteNum(s1));
        System.out.println(v.getVoteNum(s2));
        System.out.println(v.getVoteNum(s3));
    }
}
