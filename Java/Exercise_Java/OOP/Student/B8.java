package Exercise_Java.OOP.Student;

import java.util.Scanner;

public class B8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        while(n-- != 0){
            Student student = new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble());
            System.out.println(student);
            sc.nextLine();
        }
    }
}
