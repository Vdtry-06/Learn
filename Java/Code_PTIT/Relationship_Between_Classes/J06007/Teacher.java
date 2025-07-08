package Code_PTIT.Relationship_Between_Classes.J06007;

import java.io.Serializable;

public class Teacher implements Serializable {
    private String id;
    private String name;
    public Teacher(String id, String name) {
        this.id = id;
        this.name = name;
    }
    public String getId() {
        return id;
    }
    public String toString() {
        return name;
    }
}
