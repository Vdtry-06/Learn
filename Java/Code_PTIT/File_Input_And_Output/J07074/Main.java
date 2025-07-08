package Code_PTIT.File_Input_And_Output.J07074;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("MONHOC.in"));
        int n = Integer.parseInt(in.nextLine());
        ArrayList<Subject> subjects = new ArrayList<>();
        while(n-- > 0) {
            subjects.add(new Subject(in.nextLine(), in.nextLine(), Integer.parseInt(in.nextLine())));
        }
        in = new Scanner(new File("LICHGD.in"));
        int m = Integer.parseInt(in.nextLine());
        ArrayList<Group> groups = new ArrayList<>();
        while(m-- > 0) {
            groups.add(new Group(in.nextLine(), subjects, Integer.parseInt(in.nextLine()), Integer.parseInt(in.nextLine()), in.nextLine(), in.nextLine()));
        }
        String subjectId = in.nextLine();
        Collections.sort(groups);
        String subjectName = "";
        for(Subject s : subjects) {
            if(subjectId.equals(s.getId())) {
                subjectName = s.getName();
            }
        }
        System.out.println("LICH GIANG DAY MON " + subjectName + ":");
        for(Group g : groups) {
            if(g.getSubjectId().equals(subjectId)) {
                System.out.println(g);
            }
        }
    }
}
