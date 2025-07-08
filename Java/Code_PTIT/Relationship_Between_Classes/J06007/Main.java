package Code_PTIT.Relationship_Between_Classes.J06007;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Scanner;

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
            teachers.add(new Teacher(sc.next(), sc.nextLine().trim()));
        }

        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Classroom> classrooms = new ArrayList<>();
        LinkedHashMap<String, Float> map = new LinkedHashMap<>();
        while(q-- > 0) {
            classrooms.add(new Classroom(sc.next(), sc.next(), Float.parseFloat(sc.next()), teachers, subjects, map));
        }

        for (Teacher teacher : teachers) {
            float totalTime = map.getOrDefault(teacher.getId(), 0f);
            System.out.println(teacher + " " + String.format("%.2f", totalTime));
        }
    }
}
//2
//INT1155 Tin hoc co so 2
//INT1306 Cau truc du lieu va giai thuat
//2
//GV01 Nguyen Van An
//GV02 Hoang Binh Minh
//3
//GV01 INT1155 113.2
//GV02 INT1306 126.72
//GV01 INT1155 115.45