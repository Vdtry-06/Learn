package Code_PTIT.Array_Of_Objects.J05062;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        ArrayList<Student> students = new ArrayList<>();
        int cnt = 0;
        while(n-- > 0) {
            sc.nextLine();
            students.add(new Student(sc.nextLine(), Float.parseFloat(sc.next()), Integer.parseInt(sc.next()), cnt++));
        }

        students.sort(Comparator.comparing(Student::getGpa).reversed());
        TreeSet<Float> set = new TreeSet<>();
        for(Student s : students) {
            if(s.getType() != "KHONG") {
                if(m == 0) {
                    if(set.contains(s.getGpa())) {
                        s.setResult(s.getType());
                    } else {
                        s.setResult("KHONG");
                    }
                } else {
                    set.add(s.getGpa());
                    s.setResult(s.getType());
                    m--;
                }
            } else {
                s.setResult("KHONG");
            }
        }
        students.sort(Comparator.comparing(Student::getIdx));
        for(Student s : students) {
            System.out.println(s + ": " + s.getResult());
        }
    }
}
//4 2
//Nguyen Van Nam
//3.59 75
//Tran Hong Ngoc
//3.61 90
//Do Van An
//3.22 90
//Nguyen Van Hoc
//3.59 90