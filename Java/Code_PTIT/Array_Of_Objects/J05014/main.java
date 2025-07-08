package Code_PTIT.Array_Of_Objects.J05014;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Teacher_Recruitment> arrayTeacherRecruitment = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            Teacher_Recruitment teacherRecruitment = new Teacher_Recruitment(sc.nextLine(), sc.nextLine(), sc.nextFloat(), sc.nextFloat());
            sc.nextLine();
            arrayTeacherRecruitment.add(teacherRecruitment);
        }
        Collections.sort(arrayTeacherRecruitment, new Comparator<Teacher_Recruitment>() {
            @Override
            public int compare(Teacher_Recruitment o1, Teacher_Recruitment o2) {
                return o1.getTotal() > o2.getTotal() ? -1 : 1;
            }
        });
        for(Teacher_Recruitment x : arrayTeacherRecruitment) {
            System.out.println(x);
        }
    }
}
