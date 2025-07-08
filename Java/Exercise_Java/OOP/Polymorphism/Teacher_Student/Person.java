package Exercise_Java.OOP.Polymorphism.Teacher_Student;

public class Person {
    private String code, name, birth, address;

    public String getAddress() {
        return address;
    }

    public Person(String code, String name, String birth, String address) {
        this.code = code;
        this.name = name;
        this.birth = birth;
        this.address = address;
    }
    public static StringBuilder standardized_name(String s){
        s = s.toLowerCase();
        String[] words = s.split("\\s+");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            t.append(Character.toUpperCase(x.charAt(0))).append(x.substring(1)).append(" ");
        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    public static StringBuilder standardized_birth(String s){
        String[] words = s.split("/");
        StringBuilder t = new StringBuilder();
        for(String x : words){
            t.append(x.length() < 2 ?  "0" + x : x).append("/");
        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    @Override
    public String toString() {
        return code + " " + standardized_name(name) + " " + standardized_birth(birth) + " " + address;
    }
}
