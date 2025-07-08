package Exercise_Java.OOP.List_object_student;

public class Student {
    public static int count = 1;
    private String code;
    private String name;
    private String depart;
    private String birth;
    private Double gpa;

    public Student(String name, String depart, String birth, Double gpa) {
        if(count < 10) this.code = "B20DCCN00" + String.valueOf(count);
        else this.code = "B20DCCN0" + String.valueOf(count);
        count++;
        this.name = name;
        this.depart = depart;
        this.birth = birth;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        String[] t = birth.split("/");
        String res = "";
        for(int i = 0; i < t.length; i++){
            if(t[i].length() < 2){
                res += "0" + t[i];
            }
            else res += t[i];
            if(t[i].length() < 4){
                res += "/";
            }
        }
        this.birth = res;
        return code + " " + name + " " + depart + " " + birth + " " + String.format("%.2f", gpa);
    }
}
