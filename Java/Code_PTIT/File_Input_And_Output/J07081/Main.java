package Code_PTIT.File_Input_And_Output.J07081;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        Integer n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0) {
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(students);
        for(Student s : students) {
            System.out.println(s);
        }

    }
}
