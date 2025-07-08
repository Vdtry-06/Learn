package Code_PTIT.File_Input_And_Output.J07075;

public class Subject {
    private String id;
    private String name;
    private int numberOfCredits;

    public Subject(String id, String name, int numberOfCredits) {
        this.id = id;
        this.name = name;
        this.numberOfCredits = numberOfCredits;
    }
    public String getId() {return id;}
    public String getName() {return name;}
}
