package gcp.homeWork.test3.test32;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static class Util {
        public static void removeDuplicate(List<Integer> m) {
            for (int i = 0; i < m.size(); ++i) {
                for (int j = i + 1; j < m.size(); ++j) {
                    if (m.get(i) == m.get(j)) {
                        m.remove((j));
                        --j;
                    }
                }
            }
        }
    }
    public static void main(String[] args) {

        List<Integer> list = new ArrayList<>();
        //Collections.addAll()
        list.add(34);
        list.add(5);
        list.add(3);
        list.add(6);
        list.add(4);
        list.add(32);
        list.add(2);
        list.add(2);
        list.add(4);
        list.add(4);
        list.add(9);
        list.add(35);
        Util.removeDuplicate(list);
        for (int i : list) {
            System.out.print(i + " ");
        }
    }
}

