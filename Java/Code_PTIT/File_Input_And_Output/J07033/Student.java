package Code_PTIT.File_Input_And_Output.J07033;

public class Student implements Comparable<Student>{
    private String id, name, classs, email;
    public Student(String id, String name, String classs, String email) {
        this.id = id;
        this.name = processName(name);
        this.classs = classs;
        this.email = email;
    }

    private String processName(String name) {
        String [] words = name.trim().toLowerCase().split("\\s+");
        String res = "";
        for(String w: words) {
            String t = w.substring(0, 1).toUpperCase();
            res += t + w.substring(1) + " ";
        }
        return res.trim();
    }

    @Override
    public int compareTo(Student o) {
        return this.id.compareTo(o.id);
    }

    @Override
    public String toString() {
        return id + " " + name + " " + classs + " " + email;
    }
}
