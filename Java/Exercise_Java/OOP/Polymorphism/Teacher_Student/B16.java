package Exercise_Java.OOP.Polymorphism.Teacher_Student;

import java.util.ArrayList;
import java.util.Scanner;

public class B16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Student> students = new ArrayList<>();
        ArrayList<Teacher> teachers = new ArrayList<>();
        for(int i = 0; i < n; i++){
            String code = sc.nextLine();
            String name = sc.nextLine();
            String birth = sc.nextLine();
            String address = sc.nextLine();
            if(code.contains("GV")){
                teachers.add(new Teacher(code, name, birth, address, sc.nextLine(), Long.parseLong(sc.nextLine()), sc.nextLine()));
            }
            else{
                students.add(new Student(code, name, birth, address, sc.nextLine(), Double.parseDouble(sc.nextLine())));
            }
        }
        String address = sc.nextLine();
        System.out.println("DANH SACH GIAO VIEN CO DIA CHI TAI " + address + " :");
        for(Teacher x : teachers){
            if(x.getAddress().equals(address)) System.out.println(x);
        }
        System.out.println("DANH SACH SINH VIEN CO DIA CHI TAI " + address + " :");
        for(Student x : students){
            if(x.getAddress().equals(address)) System.out.println(x);
        }
    }
}
