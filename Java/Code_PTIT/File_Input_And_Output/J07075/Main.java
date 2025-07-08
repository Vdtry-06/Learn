package Code_PTIT.File_Input_And_Output.J07075;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        ArrayList<Subject> subjects = new ArrayList<Subject>();
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0) {
            subjects.add(new Subject(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("LICHGD.in"));
        ArrayList<Group> groups = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        while(m-- > 0) {
            groups.add(new Group(sc.nextLine(), subjects, Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()), sc.nextLine(), sc.nextLine()));
        }
        String teacherName = sc.nextLine();
        Collections.sort(groups);
//        String subjectId = "";
        System.out.println("LICH GIANG DAY GIANG VIEN " + teacherName + ":");
        for(Group g : groups) {
            if(g.getTeacherName().equals(teacherName)) {
                System.out.println(g);
            }
        }
    }
}
