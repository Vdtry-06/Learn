package Code_PTIT.Practice.Day2.B7;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        ArrayList<Subject> subjects = new ArrayList<>();
        HashSet<String> set = new HashSet<>();
        while(sc.hasNextLine()) {
            String id = sc.nextLine();
            String name = sc.nextLine();
            String form = sc.nextLine();
            if(!set.contains(id)) {
                set.add(id);
                subjects.add(new Subject(id, name, form));
            }
        }
        Collections.sort(subjects);
        for(Subject s : subjects) {
            System.out.println(s);
        }
    }
}
