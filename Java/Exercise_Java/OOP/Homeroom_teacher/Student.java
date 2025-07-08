package Exercise_Java.OOP.Homeroom_teacher;

public class Student extends Person{
    private String block;
    private Double gpa;

    public Student(String code, String name, String birth, String address, String block, Double gpa) {
        super(code, name, birth, address);
        this.block = block;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        return super.toString() + " " + block + " " + String.format("%.2f", gpa);
    }

    public String getBlock() {
        return block;
    }
}
