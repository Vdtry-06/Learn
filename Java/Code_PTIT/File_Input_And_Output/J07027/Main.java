package Code_PTIT.File_Input_And_Output.J07027;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = Integer.parseInt(sc.nextLine());
        int q = n;
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0) {
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("BAITAP.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Exercise> exercises = new ArrayList<>();
        while(m-- > 0) {
            exercises.add(new Exercise(sc.nextLine()));
        }
        sc = new Scanner(new File("NHOM.in"));
        ArrayList<Group> groups = new ArrayList<>();
        while(q-- > 0) {
            groups.add(new Group(sc.next(), students, Integer.parseInt(sc.next()), exercises));
        }
        Collections.sort(groups);
        for (Group group : groups) {
            System.out.println(group);
        }
    }
}
