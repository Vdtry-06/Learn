package Exercise_Java.OOP.Inheritance_Class_Person;

public class Person {
    public static int count = 1;
    private String name, birth, address, first_name, middle_name, last_name, Name;
    public Person(){
        this("", "", "");
    }
    public Person(String name, String birth, String address) {
        this.name = name;
        this.birth = birth;
        this.address = address;
        String[] words = name.split(" ");
        if(words.length > 2){
            this.first_name = words[0];
            this.middle_name = words[1];
            this.last_name = words[2];
            this.Name = words[2] + " " + words[0] + words[1];
        }
    }

    public static StringBuilder standardized_name(String s){
        s = s.toLowerCase();
        String[] words = s.split(" ");
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
            t.append(x.length() < 2 ? "0" + x : x).append("/");
        }
        t.deleteCharAt(t.length() - 1);
        return t;
    }
    @Override
    public String toString() {
        return standardized_name(name) + " " + standardized_birth(birth) + " " + address;
    }

    public StringBuilder getName() {
        return standardized_name(Name);
    }
}
