package Code_PTIT.Class_And_Object_Declaration.J04006;

public class Student {
    private String name, class1, birth, msv;
    private double gpa;
    public Student(String name, String class1, String birth, double gpa){
        this.name = name;
        this.class1 = class1;
        this.birth = birth;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        String [] date = birth.split("/");
        StringBuilder t = new StringBuilder();
        for(String x: date){
            if(x.length() < 2){
                t.append("0");
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4) t.append("/");
        }
        msv = "B20DCCN001";
        return msv + " " + name + " " + class1 + " " + t + " " + String.format("%.2f", gpa);
    }
}
