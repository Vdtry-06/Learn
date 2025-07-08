package Exercise_Java.OOP.Homeroom_teacher;

public class Teacher extends Person{
    private String department, class_;
    private int wage;

    public Teacher(String code, String name, String birth, String address, String department, int wage, String class_) {
        super(code, name, birth, address);
        this.department = department;
        this.class_ = class_;
        this.wage = wage;
    }

    @Override
    public String toString() {
        return super.toString() + " " + department + " " + wage + " " + class_;
    }

    public String getClass_() {
        return class_;
    }
}
