package Code_PTIT.File_Input_And_Output.J07060;

public class Subject {
    private String id;
    private String name;
    private String Form;
    public Subject(String id, String name, String Form) {
        this.id = id;
        this.name = name;
        this.Form = Form;
    }
    public String getId() { return id;}
    @Override
    public String toString() {
        return name;
    }
}
