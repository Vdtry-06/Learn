package Code_PTIT.Bai7;

public class Item {
    private String id;
    private String name;
    private String value; // Changed to String

    public Item(String id, String name, String value) { // Updated constructor
        this.id = id;
        this.name = name;
        this.value = value;
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public String getValue() { return value; } // Updated getter
}
