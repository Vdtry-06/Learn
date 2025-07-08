package Code_PTIT.Practice.Day1.TH9;

import java.util.Objects;

public class Contact implements Comparable<Contact>{
    private String code, name, classs, email, phone;

    public Contact(String code, String name, String classs, String email, String phone) {
        this.code = code;
        this.name = name;
        this.classs = classs;
        this.email = email;
        this.phone = "0" + phone;
    }
    @Override
    public int compareTo(Contact clas) {
        if(Objects.equals(classs, clas.classs)) {
            return code.compareTo(clas.code);
        }
        return classs.compareTo(clas.classs);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + classs + " " + email + " " + phone;
    }
}
