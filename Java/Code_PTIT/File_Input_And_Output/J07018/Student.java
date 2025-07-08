package Code_PTIT.File_Input_And_Output.J07018;

import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Student {
    private static int cnt = 1;
    private String code;
    private String name;
    private String classs;
    private String birth;
    private Double gpa;
    public Student(String name, String classs, String birth, Double gpa) throws ParseException {
        this.code = String.format("B20DCCN%03d", cnt++);
        this.name = name.toLowerCase().trim();
        this.classs = classs.trim();
        this.birth = birth.trim();
        this.gpa = gpa;
        String[] parts = this.name.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(String part : parts) {
            sb.append(Character.toUpperCase(part.charAt(0))).append(part.substring(1)).append(" ");
        }
        sb.deleteCharAt(sb.length() - 1);
        this.name = sb.toString();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        this.birth = sdf.format(sdf.parse(birth));
    }
    @Override
    public String toString() {
        return code + " " + name + " " + classs + " " + birth + " " + String.format("%.2f", gpa);
    }
}
