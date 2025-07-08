package Code_PTIT.Array_Of_Objects.J05071;

import java.io.Serializable;

public class Local implements Serializable {
    private String id;
    private String name;
    private int price;
    public Local(String id, String name, int price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public String getId() {
        return id;
    }
    public int getPrice() {
        return price;
    }

    public String toString() {
        return name;
    }
}
