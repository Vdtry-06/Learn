package Code_PTIT.File_Input_And_Output.J07060;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        Scanner sc = new Scanner(new File("MONTHI.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Subject> subjects = new ArrayList<>();
        while(n-- > 0) {
            subjects.add(new Subject(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("CATHI.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Exam> exams = new ArrayList<>();
        while(m-- > 0) {
            exams.add(new Exam(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("LICHTHI.in"));
        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Calendar> calendars = new ArrayList<>();
        while(q-- > 0) {
            calendars.add(new Calendar(sc.next(), exams, sc.next(), subjects, sc.next(), Integer.parseInt(sc.next())));
        }
        Collections.sort(calendars);
        for(Calendar calendar : calendars) {
            System.out.println(calendar);
        }
    }
}
