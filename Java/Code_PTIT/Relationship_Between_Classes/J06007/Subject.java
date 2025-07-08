package Code_PTIT.Relationship_Between_Classes.J06007;

import java.io.Serializable;

public class Subject implements Serializable {
    private String id;
    private String name;
    public Subject(String id, String name) {
        this.id = id;
        this.name = name;
    }
    public String getId() {
        return id;
    }
}
