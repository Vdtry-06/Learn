package Exercise_Java.OOP.wage_Employee;

import java.util.Scanner;

public class B7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        wage_Employee wage_employee = new wage_Employee(sc.nextLine(), sc.nextLong(), sc.nextLong(), sc.next());
        System.out.println(wage_employee);
    }
}
