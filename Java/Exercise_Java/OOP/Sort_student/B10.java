package Exercise_Java.OOP.Sort_student;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Sort_Student> lst = new ArrayList<>();
        while (n-- != 0) {
            lst.add(new Sort_Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine())));
        }
        Collections.sort(lst);
        for (Sort_Student x : lst) {
            System.out.println(x);
        }
    }
}
