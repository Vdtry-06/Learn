package Code_PTIT.File_Input_And_Output.J07034;


public class Subject implements Comparable<Subject>{
    private String code;
    public String name;
    private int cnt;

    public Subject(String code, String name, int cnt) {
        this.code = code;
        this.name = name;
        this.cnt = cnt;
    }
    @Override
    public int compareTo(Subject o) {
        return name.compareTo(o.name);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + cnt;
    }
}
