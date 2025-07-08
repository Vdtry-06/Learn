package Exercise_Java.OOP.Inheritance_Class_Person;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> lst = new ArrayList<>();
        for(int i = 0;  i < n; i++){
            String name = sc.nextLine();
            String birth = sc.nextLine();
            String address = sc.nextLine();
            String department = sc.nextLine();
            Double gpa = Double.parseDouble(sc.nextLine());
            lst.add(new Student(name, birth, address, department, gpa));
        }
        Collections.sort(lst);
        for(Student x : lst){
            System.out.println(x);
        }
    }
}
