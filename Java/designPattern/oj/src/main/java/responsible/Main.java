package responsible;

public class Main {
    public static void main(String[] args){
        int[] arr = {500, 1500, 2500, 29000};
        Manager pm = new ProjectManager();
        Manager dm = new DepartmentManager();
        Manager topm = new TopManager();
        pm.setSuccessor(dm);
        dm.setSuccessor(topm);

        for(int i = 0; i < arr.length; i++) {
            pm.handle(arr[i]);
        }
    }
}
