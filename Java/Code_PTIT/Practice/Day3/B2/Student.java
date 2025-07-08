package Code_PTIT.Practice.Day3.B2;

import java.io.Serializable;

public class Student implements Comparable<Student>, Serializable {
    private String id;
    private String name;
    private String classs;
    private String email;
    private String phone;
    public Student(String id, String name, String classs, String email, String phone) {
        this.id = id;
        this.name = name;
        this.classs = classs;
        this.email = email;
        this.phone = "0" + phone;
    }

    public int compareTo(Student o) {
        if(this.classs.compareTo(o.classs) == 0) {
            return this.id.compareTo(o.id);
        }
        return this.classs.compareTo(o.classs);
    }

    public String toString() {
        return id + " " + name + " " + classs + " " + email + " " + phone;
    }
}
