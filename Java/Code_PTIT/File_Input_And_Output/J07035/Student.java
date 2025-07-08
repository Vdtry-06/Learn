package Code_PTIT.File_Input_And_Output.J07035;

public class Student {
    private String id;
    private String name;
    private String classs;
    private String email;
    public Student(String id, String name, String classs, String email) {
        this.id = id;
        this.name = name.trim().toLowerCase();
        this.classs = classs;
        this.email = email;
        this.name = processName();
    }
    public String getId() { return id;}
    public String processName() {
        String[] parts = name.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(String part : parts) {
            sb.append(Character.toUpperCase(part.charAt(0))).append(part.substring(1).toLowerCase()).append(" ");
        }
        sb.deleteCharAt(sb.length()-1);
        return sb.toString();
    }
    @Override
    public String toString() {
        return id + " " + name + " " + classs;
    }
}
