package Exercise_Java.OOP.Class_student;

public class Student {
    private String name;
    private String birth;
    private Double a, b, c;

    public Student(String name, String birth, Double a, Double b, Double c) {
        this.name = name;
        this.birth = birth;
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public String toString() {
        return name + " " + birth + " " + String.format("%.1f", a + b + c);
    }
}
