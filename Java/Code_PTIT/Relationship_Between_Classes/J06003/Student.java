package Code_PTIT.Relationship_Between_Classes.J06003;

public class Student{
    private String studentID, name, phoneNumber;
    private int id;

    public Student(String studentID, String name, String phoneNumber,int id) {
        this.studentID = studentID;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.id = id;
    }

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return studentID + " " + name + " " + phoneNumber;
    }
}
