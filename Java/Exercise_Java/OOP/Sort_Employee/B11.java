package Exercise_Java.OOP.Sort_Employee;

import Exercise_Java.OOP.Sort_student.Sort_Student;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Sort_Employee> lst = new ArrayList<>();
        while(n-- != 0){
            lst.add(new Sort_Employee(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(),sc.nextLine()));
        }
        Collections.sort(lst);
        for(Sort_Employee x : lst){
            System.out.println(x);
        }
    }
}
