package Code_PTIT.Practice.FinalTest.ICPC;

import java.io.Serializable;

public class School implements Serializable {
    private String id;
    private String name;
    public School(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return name;
    }
}
