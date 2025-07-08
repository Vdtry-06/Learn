package Code_PTIT.Array_Of_Objects.TN02012;

import java.io.Serializable;

public class Apartment implements Serializable {
    private String id;
    private String name;
    public Apartment(String id, String name) {
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
