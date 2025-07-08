package Code_PTIT.Array_Of_Objects.J05019;

import java.time.Instant;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.LinkedHashMap;

public class Station {
    private static int cnt = 1;
    private String name;
    private String start;
    private String end;
    private int amount, idx;
    private int time;
    public Station(String name, String start, String end, int amount, int idx) {
        this.name = name;
        this.start = start;
        this.end = end;
        this.amount = amount;
        this.idx = idx;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("HH:mm");
        LocalTime startTime = LocalTime.parse(start, dtf);
        LocalTime endTime = LocalTime.parse(end, dtf);
        this.time = (int) ChronoUnit.MINUTES.between(startTime, endTime);
    }
    public int getIdx() {return idx;}
    public String getName() {return name;}
    public int getAmount() {return amount;}
    public int getTime() {return time;}

    @Override
    public String toString() {
        String id = String.format("T%02d", cnt++);
        return id + " " + name;
    }

}
