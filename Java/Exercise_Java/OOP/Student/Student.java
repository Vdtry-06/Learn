package Exercise_Java.OOP.Student;

import Exercise_Java.OOP.Class_phanso.PhanSo;

public class Student {
    public static int count = 1;
    private String name, depart, birth, code;
    private Double gpa;

    public Student(String name, String depart, String birth, Double gpa) {
        if(count < 10) this.code = "SV00" + String.valueOf(count);
        else this.code = "SV0" + String.valueOf(count);
        count++;
        this.name = name;
        this.depart = depart;
        this.birth = birth;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        String[] date = birth.split("/");
        StringBuilder t = new StringBuilder();
        for(String x: date){
            if(x.length() < 2){
                t.append(0);
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4){
                t.append("/");
            }
        }
        return code + " " + name + " " + depart + " " + t + " " + String.format("%.2f", gpa);
    }
}
