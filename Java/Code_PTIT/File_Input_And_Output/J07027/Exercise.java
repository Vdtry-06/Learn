package Code_PTIT.File_Input_And_Output.J07027;

public class Exercise {
    private static int cnt = 1;
    private String name;
    private int id;
    public Exercise(String name) {
        this.name = name;
        this.id = cnt++;
    }
    public int getId() {return id;}
    @Override
    public String toString() {
        return id + " " + name;
    }
}
