package Code_PTIT.Practice.FinalTest.Employee;

import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Employee> employees = new ArrayList<>();
        while(n-- > 0) {
            employees.add(new Employee(sc.nextLine(), sc.nextLine().trim(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(employees);
        for(Employee e : employees) {
            System.out.println(e);
        }
    }
}
//2
//01T
//Nguyen Van An
//08:00
//17:30
//06T
//Tran Hoa Binh
//09:05
//17:00