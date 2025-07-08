package Code_PTIT.Relationship_Between_Classes.J06003;

public class Group {
    private static int cnt = 1;
    private String nameGroup;
    private int id;

    public Group(String nameGroup) {
        this.nameGroup = nameGroup;
        this.id = cnt++;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return nameGroup;
    }
    @Override
    public String toString() {
        return nameGroup;
    }
}
