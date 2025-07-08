package Code_PTIT.Practice.Day2.B13;

public class Student {
    private String id, name, phone, email;
    public Student(String id, String name, String phone, String email) {
        this.id = id.trim();
        this.name = name;
        this.phone = phone;
        this.email = email;
    }
    public String getId() {
        return id;
    }
    @Override
    public String toString() {
        return id + " " + name;
    }
}
