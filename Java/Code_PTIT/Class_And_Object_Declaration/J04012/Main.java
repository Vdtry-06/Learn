package Code_PTIT.Class_And_Object_Declaration.J04012;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Employee employee = new Employee(sc.nextLine(), sc.nextLong(), sc.nextLong(), sc.next());
        System.out.println(employee);
    }
}
