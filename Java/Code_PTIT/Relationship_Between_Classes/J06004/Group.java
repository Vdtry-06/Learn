package Code_PTIT.Relationship_Between_Classes.J06004;

public class Group {
    private static int cnt = 1;
    private String name;
    private int id;

    public Group(String name) {
        this.name = name;
        id = cnt++;
    }
    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    @Override
    public String toString() {
        return id + " " + name;
    }
}
