package Basic_java.Bai26_oop;

import Basic_java.School.Student;

public class OOP1 {
    public static void main(String[] args) {
        Student sv1 = new Student();
        Student sv2 = new Student();
        sv1.information();
        sv2.information();
        Student sv3 = new Student("Tun");
        sv3.information();
        Student sv4 = new Student("Tun", 3.4);
        sv4.information();
        System.out.println(sv4.getName());
        System.out.println(sv4.getGpa());

        // thay doi ten sinh vien 4
        sv4.setName("Trong");
        sv4.information();
        sv4.setGpa(25.0);
        sv4.information();

        // test phuong thuc kieu tra ve
        double dtbsvt4 = sv4.counting_DTB(8.8, 8.5);
        System.out.println(dtbsvt4);
        sv4.information();

        // test phuong thuc toString
        System.out.println(sv4);

        // support Method and service Method
        sv4.checkGpa_hople();

        // overloading
        double testd = sv4.counting_DTB(5, 6, 7);
        System.out.println(testd);
        double testd2 = sv4.counting_DTB(8, 9);
        System.out.println(testd2);
        double res = sv4.sumd_point(1, 2, 3, 4, 5, 6, 7, 8);
        System.out.println(res);
    }
}
