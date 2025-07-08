package Code_PTIT.File_Input_And_Output.J07036;

public class Subject {
    private String id;
    private String name;
    private int numberOfCredit;
    public Subject(String id, String name, int numberOfCredit) {
        this.id = id;
        this.name = name;
        this.numberOfCredit = numberOfCredit;
    }
    public String getId() {
        return id;
    }
    @Override
    public String toString() {
        return id + " " + name;
    }
}
