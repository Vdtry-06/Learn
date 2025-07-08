package Exercise_Java.OOP.Sort_Student3;

public class Sort_code implements Comparable<Sort_code>{
    private String code, name, department, gmail;

    public Sort_code(String code, String name, String department, String gmail) {
        this.code = code;
        this.name = name;
        this.department = department;
        this.gmail = gmail;
    }
    @Override
    public int compareTo(Sort_code o) {
        return this.code.compareTo(o.code);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + department + " " + gmail;
    }
}
