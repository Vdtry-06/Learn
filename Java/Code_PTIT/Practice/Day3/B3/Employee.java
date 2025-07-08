package Code_PTIT.Practice.Day3.B3;

import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Employee implements Comparable<Employee>,Serializable {
    private String id, name;
    private long time_worked;
    public Employee(String id, String name, String st, String en) throws ParseException {
        this.id = id;
        this.name = name;
        SimpleDateFormat formatter = new SimpleDateFormat("HH:mm");
        Date in = formatter.parse(st);
        Date out = formatter.parse(en);
        this.time_worked = out.getTime() - in.getTime() - 60 * 60 * 1000;
    }

    public int compareTo(Employee other) {
        if(this.time_worked == other.time_worked) {
            return this.id.compareTo(other.id);
        }
        return Math.toIntExact(other.time_worked - this.time_worked);
    }

    public String toString() {
        long h = this.time_worked / (1000 * 60 * 60);
        long m = (this.time_worked - h * 3600000) / 60000;
        return id + " " + name + " " + Long.toString(h) + " gio " + Long.toString(m) + " phut " + (h >= 8 ? "DU": "THIEU");
    }
}
