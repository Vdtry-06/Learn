package UDP;

import java.io.Serializable;

public class Student implements Serializable {
    private static final long serialVersionUID = 20171107;
    private String id;
    private String code;
    private String name;
    private String email;

    public Student(String id, String code, String name, String email) {
        this.id = id;
        this.code = code;
        this.name = name;
        this.email = email;
    }

    public Student(String code) {
        this.code = code;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        String[] parts = name.split(" ");
        String newName = "";
        String email = parts[parts.length - 1].toLowerCase();
        for (String s: parts) {
            newName += s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase() + " ";
            email += s.substring(0, 1).toLowerCase();
        }
        newName = newName.substring(0, newName.length() - 1);
        email = email.substring(0, email.length() - 1) + "@ptit.edu.vn";
        setEmail(email);
        this.name = newName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
