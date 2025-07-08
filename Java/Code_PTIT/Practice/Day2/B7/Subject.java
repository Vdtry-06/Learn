package Code_PTIT.Practice.Day2.B7;

public class Subject implements Comparable<Subject>{
    private String id, name, form;

    public Subject(String id, String name, String form) {
        this.id = id;
        this.name = name;
        this.form = form;
    }
    public String getId() {
        return id;
    }
    @Override
    public int compareTo(Subject o) {
        return this.id.compareTo(o.id);
    }
    @Override
    public String toString() {
        return id + " " + name + " " + form; 
    }

}
