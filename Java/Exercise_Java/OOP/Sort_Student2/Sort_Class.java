package Exercise_Java.OOP.Sort_Student2;

public class Sort_Class implements Comparable<Sort_Class>{
    private String code, name, department, gmail;

    public Sort_Class(String code, String name, String department, String gmail) {
        this.code = code;
        this.name = name;
        this.department = department;
        this.gmail = gmail;
    }
    @Override
    public int compareTo(Sort_Class o) {
        return this.department.compareTo(o.department);
    }

    @Override
    public String toString() {
        return code + " " + name + " " + department + " " + gmail;
    }
}
