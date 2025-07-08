package Exercise_Java.OOP.Inheritance_Class_Person;

public class Student extends Person implements Comparable<Student>{
    private String code, department;
    private Double gpa;

    public Student(String name, String birth, String address, String department, Double gpa) {
        super(name, birth, address);
        this.code = String.format("%04d", count++);
        this.department = department;
        this.gpa = gpa;
    }
    @Override
    public int compareTo(Student o) {
        if(this.getName().equals(o.getName())){
            return this.code.compareTo(o.code);
        }
        return this.getName().compareTo(o.getName());
    }
    @Override
    public String toString() {
        return code + " " + super.toString() + " " + department + " " + String.format("%.2f", gpa);
    }
}
