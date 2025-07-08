package Exercise_Java.OOP.Homeroom_teacher;

import java.util.ArrayList;
import java.util.Scanner;

public class B17 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Teacher> teachers = new ArrayList<>();
        ArrayList<Student> students = new ArrayList<>();
        for(int i = 0; i < n; i++){
            String code = sc.nextLine();
            String name = sc.nextLine();
            String birth = sc.nextLine();
            String address = sc.nextLine();
            if(code.contains("GV")){
                teachers.add(new Teacher(code, name, birth, address, sc.nextLine(), Integer.parseInt(sc.nextLine()), sc.nextLine()));
            }
            else{
                students.add(new Student(code, name, birth, address, sc.nextLine(), Double.parseDouble(sc.nextLine())));
            }
        }
        String class_ = sc.nextLine();
        System.out.println("DANH SACH GIAO VIEN PHU TRACH LOP " + class_ + " :");
        for(Teacher x: teachers){
            if(x.getClass_().equals(class_)){
                System.out.println(x);
            }
        }
        System.out.println("DANH SACH SINH VIEN LOP " + class_ + " :");
        for(Student x : students){
            if(x.getBlock().equals(class_)){
                System.out.println(x);
            }
        }
    }
}
