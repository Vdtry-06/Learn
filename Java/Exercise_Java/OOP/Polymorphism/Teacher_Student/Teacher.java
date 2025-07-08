package Exercise_Java.OOP.Polymorphism.Teacher_Student;

public class Teacher extends Person{
    private String department, lop;
    private Long wage;

    public Teacher(String code, String name, String birth, String address, String department, Long wage, String lop) {
        super(code, name, birth, address);
        this.department = department;
        this.wage = wage;
        this.lop = lop;
    }
    @Override
    public String toString() {
        return super.toString() + " " + department + " " + wage;
    }
}
