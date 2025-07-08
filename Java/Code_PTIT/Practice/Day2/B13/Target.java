package Code_PTIT.Practice.Day2.B13;

public class Target {
    private static int cnt = 1;
    private String teacherName, name, id;
    public Target(String teacherName, String name) {
        this.id = String.format("DT%03d", cnt++);
        this.teacherName = teacherName;
        this.name = name;
    }
    public String getId() {
        return id;
    }
    @Override
    public String toString() {
        return name + " " + teacherName;
    }
}
