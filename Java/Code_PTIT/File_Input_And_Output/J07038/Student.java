package Code_PTIT.File_Input_And_Output.J07038;

public class Student {
    private String id, name, classs, email;
    public Student(String id, String name, String classs, String email) {
        this.id = id;
        this.name = processName(name);
        this.classs = classs;
        this.email = email;
    }

    public String getId() {
        return id;
    }

    private String processName(String name) {
        String [] words = name.trim().toLowerCase().split("\\s+");
        String s = "";
        for(String word : words) {
            String t = word.substring(0, 1).toUpperCase();
            s += t + word.substring(1) + " ";
        }
        return s.trim();
    }

    @Override
    public String toString() {
        return id + " " + name + " " + classs;
    }
}
