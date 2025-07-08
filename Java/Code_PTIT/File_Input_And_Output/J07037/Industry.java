package Code_PTIT.File_Input_And_Output.J07037;

public class Industry implements Comparable<Industry>{
    private String code, name;
    private int Student_count;

    public Industry(String code, String name, int student_count) {
        this.code = code;
        this.name = name;
        this.Student_count = student_count;
    }
    @Override
    public int compareTo(Industry o) {
        return code.compareTo(o.code);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + Student_count;
    }
}
