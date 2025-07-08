package Code_PTIT.File_Input_And_Output.J07035;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        while(n-- > 0){
            students.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("MONHOC.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Subject> subjects = new ArrayList<>();
        while(m-- > 0) {
            subjects.add(new Subject(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("BANGDIEM.in"));
        int q = Integer.parseInt(sc.nextLine());
        ArrayList<ScoreTable> scoreTables = new ArrayList<>();
        while(q-- > 0) {
            scoreTables.add(new ScoreTable(sc.next(), students, sc.next(), subjects, Float.parseFloat(sc.nextLine())));
        }
        Collections.sort(scoreTables);
        int k = Integer.parseInt(sc.nextLine());
        while(k-- > 0) {
            String subjectId = sc.nextLine();
            String subjectName = "";
            for(Subject s : subjects){
                if(subjectId.equals(s.getId())) {
                    subjectName = s.getName();
                }
            }
            System.out.println("BANG DIEM MON " + subjectName + ":");
            for(ScoreTable s : scoreTables){
                if(subjectId.equals(s.getSubjectId())) {
                    System.out.println(s);
                }
            }
        }
    }
}
