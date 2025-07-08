package Exercise_Java.OOP.List_Student;

public class List {
    private String code, name, department, gmail;

    public List(String code, String name, String department, String gmail) {
        this.code = code;
        this.name = name;
        this.department = department;
        this.gmail = gmail;
    }

    public String getDepartment() {
        return department;
    }

    public StringBuilder stand(String s){
        s = s.toLowerCase();
        String[] words = s.split("\\s+");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            t.append(Character.toUpperCase(x.charAt(0)));
            t.append(x.substring(1));
            t.append(" ");
        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    @Override
    public String toString() {
        return code + " " + stand(name) + " " + department + " " + gmail;
    }
}
