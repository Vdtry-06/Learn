package Code_PTIT.Array_Of_Objects.J05004;

public class Student {
    private static int count = 1;
    private String name, classSt, date, id;
    private float gpa;

    public Student(String name, String classSt, String date, float gpa) {
        this.id = String.format("B20DCCN%03d", count++);
        this.name = formatName(name);
        this.classSt = classSt;
        this.date = date;
        this.gpa = gpa;
    }
    private String formatName(String name){
        String [] words = name.trim().split("\\s+");
        String res = "";
        for(String x: words){
            res += x.substring(0, 1).toUpperCase() + x.substring(1).toLowerCase() + " ";
        }
        return res.substring(0, res.length() - 1);
    }
    @Override
    public String toString() {
        return id + " " + name + " " + classSt + " " + date + " " + String.format("%.2f", gpa);
    }
}
