package Code_PTIT.File_Input_And_Output.J07028;

import java.io.Serializable;

public class Teacher implements Serializable {
    private String id;
    private String name;
    public Teacher(String id, String name) {
        this.id = id;
        this.name = name;
    }
    public String getId() {return id;}
    public String toString() {
        return name;
    }
}
