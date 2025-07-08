package Code_PTIT.Array_Of_Objects.J05065;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Employee> employees = new ArrayList<>();
        TreeMap<String, Integer> treeMap = new TreeMap<>();

        while(n-- > 0) {
            employees.add(new Employee(sc.next(), sc.nextLine().trim(), treeMap));
        }
        Collections.sort(employees);
        int m = Integer.parseInt(sc.nextLine());
        while(m-- > 0) {
            String s = sc.nextLine();
            for(Employee e : employees) {
                if(s.equals(e.getPos())){
                    System.out.println(e);
                }
            }
            System.out.println();
        }
    }
}
//6
//GD08001 Nguyen Kim Loan
//TP11002 Hoang Thanh Tuan
//TP05001 Tran Binh Nguyen
//PP06002 Phan Trung Tuan
//PP06001 Tran Quoc Huy
//NV04003 Vo Van Lan
//2
//TP
//PP