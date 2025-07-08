package Code_PTIT.Array_Of_Objects.J05006;

import java.util.ArrayList;
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
        for(Employee x : arrayEmployee) {
            System.out.println(x);
        }
    }
}
