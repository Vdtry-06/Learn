package Code_PTIT.Array_Of_Objects.J05007;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Employee> arrayEmployee = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            Employee employee = new Employee(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            arrayEmployee.add(employee);
        }
        Collections.sort(arrayEmployee, new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                if(o1.getYear().compareTo(o2.getYear()) != 0) return o1.getYear().compareTo(o2.getYear());
                else if (o1.getMonth().compareTo(o2.getMonth()) != 0) return o1.getMonth().compareTo(o2.getMonth());
                else return o1.getDay().compareTo(o2.getDay());
            }
        });
        for (Employee x : arrayEmployee) {
            System.out.println(x);
        }
    }
}
