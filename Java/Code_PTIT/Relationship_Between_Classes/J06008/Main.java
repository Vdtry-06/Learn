package Code_PTIT.Relationship_Between_Classes.J06008;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Subject> subjects = new ArrayList<>();
        while(n-- > 0) {
            subjects.add(new Subject(sc.next(), sc.nextLine()));
        }

        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Teacher> teachers = new ArrayList<>();
        while(m-- > 0) {
            teachers.add(new Teacher(sc.next(), sc.nextLine()));
        }

        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Classification> classifications = new ArrayList<>();
        TreeMap<String, Float> totalTime = new TreeMap<>();
        while(q-- > 0) {
            classifications.add(new Classification(sc.next(), sc.next(), Float.parseFloat(sc.nextLine()), teachers, subjects, totalTime));
        }
        String id = sc.nextLine();

        Set<Teacher> teacherSet = new HashSet<>();
        for(Classification c : classifications) {
            if(id.equals(c.getTeacherId())) {
                if(!teacherSet.contains(c.getTeacherName())) {
                    System.out.println("Giang vien: " + c.getTeacherName());
                    teacherSet.add(c.getTeacherName());
                }
                System.out.println(c);
            }
        }
        System.out.println("Tong: " + String.format("%.2f", totalTime.get(id)));

    }
}
//2
//INT1155 Tin hoc co so 2
//INT1306 Cau truc du lieu va giai thuat
//2
//GV01 Nguyen Van An
//GV02 Hoang Binh Minh
//2
//GV01 INT1155 113.2
//GV01 INT1306 126.72
//GV01