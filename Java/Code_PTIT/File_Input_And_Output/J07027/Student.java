package Code_PTIT.File_Input_And_Output.J07027;

public class Student {
    private String id;
    private String name;
    private String phoneNumber;

    public Student(String id, String name, String phoneNumber) {
        this.id = id;
        this.name = name;
        this.phoneNumber = phoneNumber;
    }
    public String getId() {return id;}
    @Override
    public String toString() {
        return id + " " + name + " " + phoneNumber;
    }
}
