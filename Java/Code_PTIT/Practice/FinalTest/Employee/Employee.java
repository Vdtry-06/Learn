package Code_PTIT.Practice.FinalTest.Employee;

import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Employee implements Comparable<Employee>, Serializable {
    private String id;
    private String name;
    private String start;
    private String end;
    private long time;
    public Employee(String id, String name, String start, String end) throws ParseException {
        this.id = id;
        this.name = name;
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        Date in = sdf.parse(start);
        Date out = sdf.parse(end);
        this.time = out.getTime() - in.getTime() - 60 * 60 * 1000;
    }

    public int compareTo(Employee o) {
        if(o.time == this.time) {
            return this.id.compareTo(o.id);
        }
        return (int) (o.time - this.time);
    }

    public String toString() {

        long hours = time / (1000 * 60 * 60);
        long minutes = (time - hours * 1000 * 60 * 60) / (1000 * 60);
        return id + " " + name + " " + hours + " gio " + minutes + " phut "  + ((hours >= 8) ? "DU" : "THIEU");
    }

}
