package Code_PTIT.Relationship_Between_Classes.J06008;

import java.io.Serializable;

public class Teacher implements Serializable {
    private String id;
    private String name;
    public Teacher(String id, String name) {
        this.id = id.trim();
        this.name = name.trim();
    }
    public String getId() {
        return id;
    }

    public String toString() {
        return name;
    }
}
