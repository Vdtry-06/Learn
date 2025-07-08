package Code_PTIT.Relationship_Between_Classes.J06004;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        ArrayList<Student> arrayStudent = new ArrayList<>();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            arrayStudent.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextInt()));
            sc.nextLine();
        }
        ArrayList<Group> arrayGroup = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            arrayGroup.add(new Group(sc.nextLine()));
        }
        Collections.sort(arrayStudent);
        for (Student x : arrayStudent) {
            for (Group y : arrayGroup) {
                if(x.getId() == y.getId()) {
                    System.out.println(x + " " + y);
                }
            }
        }
    }
}
