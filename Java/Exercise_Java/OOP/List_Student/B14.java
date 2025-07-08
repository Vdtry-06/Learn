package Exercise_Java.OOP.List_Student;

import java.util.ArrayList;
import java.util.Scanner;

public class B14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<List> lst = new ArrayList<>();
        while(n-- != 0){
            lst.add(new List(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        int m = Integer.parseInt(sc.nextLine());
        while(m-- != 0){
            String t = sc.nextLine();
            System.out.println("DANH SACH SINH VIEN LOP " + t + " :");
            for(List x : lst){
                if(x.getDepartment().equals(t)){
                    System.out.println(x);
                }
            }
        }
    }
}
