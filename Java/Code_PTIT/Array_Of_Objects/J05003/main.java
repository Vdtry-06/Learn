package Code_PTIT.Array_Of_Objects.J05003;

import java.util.ArrayList;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Student> arrayStudent = new ArrayList<>();
        for(int i = 1; i <= n; i++){
            sc.nextLine();
            Student student = new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble());
            student.setId("B20DCCN" + String.format("%03d", i));
            arrayStudent.add(student);
        }
        for(Student x : arrayStudent) {
            System.out.println(x.toString());
        }
    }
}
