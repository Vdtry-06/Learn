package Code_PTIT.File_Input_And_Output.J07081;

import java.io.Serializable;
import java.util.Arrays;

public class Student implements Comparable<Student>, Serializable {
    private String id;
    private String name, firstname, lastname, midname;
    private String phone;
    private String email;
    public Student(String id, String name, String phone, String email) {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.email = email;
        String [] words = name.split(" ");
        this.firstname = words[words.length - 1];
        this.midname = Arrays.toString(Arrays.copyOfRange(words, 1, words.length - 1));
        this.lastname = words[0];
    }

    public int compareTo(Student other) {
        if(this.firstname.compareTo(other.firstname) == 0) {
            if(this.lastname.compareTo(other.lastname) == 0) {
                if(this.midname.compareTo(other.midname) == 0) {
                    return this.id.compareTo(other.id);
                }
                return this.midname.compareTo(other.midname);
            }
            return this.lastname.compareTo(other.lastname);
        }
        return this.firstname.compareTo(other.firstname);
    }

    public String toString() {
        return id + " " + name + " " + phone + " " + email;
    }
}
