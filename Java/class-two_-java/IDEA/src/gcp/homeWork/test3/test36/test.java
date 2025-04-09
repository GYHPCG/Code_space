package gcp.homeWork.test3.test36;

public class test {
    public static void main(String[] args) {

        A o1 = A.getInstance();

        A o2 = A.getInstance();

        if (o1.equals(o2)) {

            System.out.println("o1 and o2 are the same object!");

        }

    }
}
