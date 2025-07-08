package Code_PTIT.Array_Of_Objects.J05003;

public class Student {
    private String name, classSt, date, id;
    private double gpa;

    public Student(String name, String classSt, String date, double gpa) {
        this.name = name;
        this.classSt = classSt;
        this.date = date;
        this.gpa = gpa;
    }

    public void setId(String id) {
        this.id = id;
    }
    public String getId() {
        return id;
    }
    public void DATE(String s) {
        String [] date = s.split("/");
        StringBuilder t = new StringBuilder();
        for(String x: date){
            if(x.length() < 2){
                t.append("0");
                t.append(x);
            }
            else t.append(x);
            if(x.length() < 4) t.append("/");
        }
        this.date = t.toString();
    }
    @Override
    public String toString() {
        DATE(date);
        return id + " " + name + " " + classSt + " " + date + " " + String.format("%.2f", gpa);
    }
}

