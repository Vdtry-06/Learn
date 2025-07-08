package Exercise_Java.OOP.Sort_student;

public class Sort_Student implements Comparable<Sort_Student>{
    private static int count = 1;
    private String name, department, birth, code;
    private Double gpa;

    public Sort_Student(String name, String department, String birth, Double gpa) {
        this.code = String.valueOf(count);
        while(this.code.length() < 3){
            this.code = "0" + this.code;
        }
        count++;
        this.code = "SV" + this.code;
        this.name = name;
        this.department = department;
        this.birth = birth;
        this.gpa = gpa;
    }
    public StringBuilder stand(String s) {
        s = s.toLowerCase();
        String[] words = s.split(" ");
        StringBuilder t = new StringBuilder();
        for (String x : words) {
            t.append(Character.toUpperCase(x.charAt(0))).append(x.substring(1)).append(" ");
        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    @Override
    public int compareTo(Sort_Student o) {
        if(this.gpa.equals(o.gpa)){
            return this.code.compareTo(o.code);
        }
        return o.gpa.compareTo(this.gpa);
    }

    @Override
    public String toString() {
        String[] date = birth.split("/");
        StringBuilder t = new StringBuilder();
        for(String x : date){
            if(x.length() < 2){
                t.append("0");
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4){
                t.append("/");
            }
        }
        return code + " " + stand(name) + " " + department + " " + t + " " + String.format("%.2f", gpa);
    }
}
