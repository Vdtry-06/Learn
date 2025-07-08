package Code_PTIT.Relationship_Between_Classes.J06004;

public class Student implements Comparable<Student>{
    private String msv, name, phoneNumber;
    private int id;

    public Student(String msv, String name, String phoneNumber, int id) {
        this.msv = msv;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.id = id;
    }
    public int getId() {
        return id;
    }
    @Override
    public int compareTo(Student o) {
        return msv.compareTo(o.msv);
    }
    @Override
    public String toString() {
        return msv + " " + name + " " + phoneNumber;
    }
}
