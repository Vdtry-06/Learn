package Code_PTIT.Practice.FinalTest.Report;

import java.io.Serializable;

public class Student implements Serializable {
    private String id, name, description;
    public Student(String id, String name, String description) {
        this.id = id;
        this.name = name;
        this.description = description;
    }

    public String getId() { return id;}

    public String toString() {
        return id + " " + name + " " + description;
    }
}
