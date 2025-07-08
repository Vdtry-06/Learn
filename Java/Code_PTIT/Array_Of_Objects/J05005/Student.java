package Code_PTIT.Array_Of_Objects.J05005;

public class Student {
    private static int count = 1;
    private String name, classs, date, id;
    private float gpa;

    public Student(String name, String classs, String date, float gpa) {
        this.id = String.format("B20DCCN%03d", count++);
        this.name = formatName(name);
        this.classs = classs;
        this.date = date;
        this.gpa = gpa;
    }
    public String formatName(String name) {
        String [] words = name.trim().split("\\s+");
        String res = "";
        for(String x: words) {
            res += x.substring(0, 1).toUpperCase() + x.substring(1).toLowerCase () + " ";
        }
        return res.substring(0, res.length() - 1);
    }

    public float getGpa() {
        return gpa;
    }

    @Override
    public String toString() {
        return id + " " + name + " " + classs + " " + date + " " + String.format("%.2f", gpa);
    }
}
