package Code_PTIT.Relationship_Between_Classes.J06003;

import java.util.ArrayList;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arrayStudent = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arrayStudent.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextInt()));
            sc.nextLine();
        }
        ArrayList<Group> arrayGroup = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            arrayGroup.add(new Group(sc.nextLine()));
        }
        int q = Integer.parseInt(sc.nextLine());
        for(int i = 0; i < q; i++) {
            int x = Integer.parseInt(sc.nextLine());
            for (Group y : arrayGroup) {
                if (x == y.getId()) {
                    System.out.println("DANH SACH NHOM " + y.getId() + ":");
                    for(Student z : arrayStudent) {
                        if(z.getId() == x) System.out.println(z);
                    }
                    System.out.println("Bai tap dang ky: " + y.getName());
                }
            }
        }
    }
}
