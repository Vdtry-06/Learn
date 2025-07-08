package Code_PTIT.File_Input_And_Output.J07028;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        ArrayList<Subject> subjects = new ArrayList<>();
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0) {
            subjects.add(new Subject(sc.next(), sc.nextLine().trim()));
        }

        sc = new Scanner(new File("GIANGVIEN.in"));
        ArrayList<Teacher> teachers = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        while(m-- > 0) {
            teachers.add(new Teacher(sc.next(), sc.nextLine().trim()));
        }

        sc = new Scanner(new File("GIOCHUAN.in"));
        ArrayList<StandardTime> standardTimes = new ArrayList<>();
        int p = Integer.parseInt(sc.nextLine());
        while(p-- > 0) {
            standardTimes.add(new StandardTime(sc.next(), teachers, sc.next(), subjects, Float.parseFloat(sc.nextLine().trim())));
        }
        StandardTime.calculateTotalTime(teachers, standardTimes);
    }
}
