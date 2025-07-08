package Code_PTIT.Array_Of_Objects.J05005;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class main {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> arrayStudent = new ArrayList<>();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        int n = sc.nextInt();
        for(int i = 0; i < n; ++i) {
            sc.nextLine();
            Student student = new Student(sc.nextLine(), sc.nextLine(), sdf.format(sdf.parse(sc.nextLine())), sc.nextFloat());
            arrayStudent.add(student);
        }
        Collections.sort(arrayStudent, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.getGpa() > o2.getGpa() ? -1 : 1;
            }
        });
        for(Student x: arrayStudent) {
            System.out.println(x.toString());
        }
    }
}
