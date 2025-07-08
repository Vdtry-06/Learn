package Code_PTIT.Practice.Day3.B4;

import java.io.Serializable;

public class Student implements Serializable {
    private String id;
    private String name;
    private String topic;
    public Student(String id, String name, String topic) {
        this.id = id;
        this.name = name;
        this.topic = topic;
    }
    public String getId() {
        return id;
    }

    public String toString() {
        return id + " " + name + " " + topic;
    }

}
