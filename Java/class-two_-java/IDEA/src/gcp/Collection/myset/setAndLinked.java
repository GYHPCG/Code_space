package gcp.Collection.myset;

import java.util.HashSet;
import java.util.LinkedHashSet;

public class setAndLinked {
    public static void main(String[] args) {
        HashSet<Integer> hs = new HashSet<>();
        hs.add(9);
        hs.add(78);
        hs.add(3);
        hs.add(8);
        System.out.println(hs);
        LinkedHashSet<Integer> Lhs = new LinkedHashSet<>();
        Lhs.add(9);
        Lhs.add(78);
        Lhs.add(3);
        Lhs.add(8);
        System.out.println(Lhs);
    }
}
