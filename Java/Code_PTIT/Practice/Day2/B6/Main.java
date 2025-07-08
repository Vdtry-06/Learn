package Code_PTIT.Practice.Day2.B6;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("LUYENTAP.in"));
        int n = sc.nextInt();
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0) {
            sc.nextLine();
            String name = sc.nextLine();
            int correct = Integer.parseInt(sc.next());
            int submit = Integer.parseInt(sc.next());

            students.add(new Student(name, correct, submit));
        }
        Collections.sort(students);
        for(Student s : students) {
            System.out.println(s.toString());
        }
    }
}
