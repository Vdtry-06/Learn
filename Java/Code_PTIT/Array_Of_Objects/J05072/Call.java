package Code_PTIT.Array_Of_Objects.J05072;

import java.io.Serializable;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

public class Call implements Serializable, Comparable<Call> {
    private Local local;
    private String phone;
    private String start;
    private String end;
    private long minute;
    private int price;

    public Call(String phone, String start, String end, ArrayList<Local> locals) {
        this.phone = phone;
        this.start = start;
        this.end = end;
        this.minute = time(start, end);
        this.local = findPhoneByLocals(phone, locals);
        if(local == null) {
            this.minute = (int) Math.ceil((double) minute / 3);
            this.price = (int) this.minute * 800;
        }

    }

    private long time(String start, String end) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("HH:mm");
        LocalTime startTime = LocalTime.parse(start, dtf);
        LocalTime endTime = LocalTime.parse(end, dtf);
        return ChronoUnit.MINUTES.between(startTime, endTime);
    }

    private Local findPhoneByLocals(String phone, ArrayList<Local> locals) {
        for (Local local : locals) {
            if(phone.substring(1, 3).equals(local.getId())) {
                this.price = (int) this.minute * local.getPrice();
                return local;
            }
        }
        return null;
    }

    public int compareTo(Call o) {
        return o.price - this.price;
    }

    public String toString() {
        if(local == null) {
            return phone + " Noi mang " + (int) minute + " " + price;
        }
        return phone + " " + local + " " + (int) minute + " " + price;
    }
}
