package Exercise_Java.OOP.Class_student2;

public class Student {
    private String name, depart, birth, id;
    private Double gpa;

    public Student(String name, String depart, String birth, Double gpa) {
        this.name = name;
        this.depart = depart;
        this.birth = birth;
        this.gpa = gpa;
        this.id = "SV001";
    }

    @Override
    public String toString() {
        String[] date = birth.split("/");
        StringBuilder t = new StringBuilder();
        for(String x : date){
            if(x.length() < 2){
                t.append(0);
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4){
                t.append("/");
            }
        }
        return id + " " + name + " " + depart + " " + t + " " + String.format("%.1f", gpa);
    }
}
