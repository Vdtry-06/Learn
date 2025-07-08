package Code_PTIT.File_Input_And_Output.J07010;

import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Student {
    private static int cnt = 1;
    private String name, classs, date, id;
    private float gpa;

    public Student(String name, String classs, String date, float gpa) throws ParseException {
        this.id = String.format("B20DCCN%03d", cnt++);
        this.name = name;
        this.classs = classs;
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        this.date = sdf.format(sdf.parse(date));
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        return id + " " + name + " " + classs + " " + date + " " + String.format("%.2f", gpa);
    }
}
