package Code_PTIT.Practice.FinalTest.Report;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("BAITAP.in"));
        ArrayList<Student> students = new ArrayList<>();
        while(sc.hasNextLine()) {
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("BAOCAO.in"));
        ArrayList<Report> reports = new ArrayList<>();
        while(sc.hasNextLine()) {
            reports.add(new Report(sc.nextLine(), sc.nextLine(), students));
        }
        Collections.sort(reports);
        Report.result(students, reports);
    }
}
