package Code_PTIT.Array_Of_Objects.J05004;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class main {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            sc.nextLine();
            Student student = new Student(sc.nextLine(), sc.nextLine(), sdf.format(sdf.parse(sc.nextLine())), sc.nextFloat());
            System.out.println(student);
        }
    }
}
