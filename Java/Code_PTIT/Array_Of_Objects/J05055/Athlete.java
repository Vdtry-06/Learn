package Code_PTIT.Array_Of_Objects.J05055;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.LinkedHashMap;

public class Athlete implements Comparable<Athlete>, Serializable {
    private static int cnt = 1;
    private String name, birth, start, end;
    private int age;
    private String id;
    private String factTime;
    private LocalTime pre;
    private String res;
    private int stt;
    public Athlete(String name, String birth, String start, String end, int stt) {
        this.name = name;
        this.birth = birth;
        this.start = start;
        this.end = end;
        this.stt = stt;

        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate birthDate = LocalDate.parse(birth, dtf);
        LocalDate today = LocalDate.of(2021, 1, 1);
        this.age = today.getYear() - birthDate.getYear();
        DateTimeFormatter dtf2 = DateTimeFormatter.ofPattern("HH:mm:ss");
        LocalTime startTime = LocalTime.parse("00:00:00", dtf2);
        if(this.age >= 32) this.pre = startTime.plusSeconds(3);
        else if(this.age >= 25) this.pre = startTime.plusSeconds(2);
        else if(this.age >= 18) this.pre = startTime.plusSeconds(1);
        else this.pre = startTime;

        this.factTime = runningTime(this.start, this.end);
        LocalTime endTime = LocalTime.parse(this.factTime, dtf2);

        if (endTime.isBefore(startTime)) {
            endTime = endTime.plusHours(24);
        }
        long hours = ChronoUnit.HOURS.between(this.pre, endTime);
        long minutes = ChronoUnit.MINUTES.between(this.pre, endTime) % 60;
        long seconds = ChronoUnit.SECONDS.between(this.pre, endTime) % 60;
        this.res = String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    private String runningTime(String start, String end) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("HH:mm:ss");
        LocalTime startTime = LocalTime.parse(start, dtf);
        LocalTime endTime = LocalTime.parse(end, dtf);
        if (endTime.isBefore(startTime)) {
            endTime = endTime.plusHours(24);
        }
        long hours = ChronoUnit.HOURS.between(startTime, endTime);
        long minutes = ChronoUnit.MINUTES.between(startTime, endTime) % 60;
        long seconds = ChronoUnit.SECONDS.between(startTime, endTime) % 60;
        return String.format("%02d:%02d:%02d", hours, minutes, seconds);
    }

    public int getStt() {return stt;}
    public String getRes() {return res;}

    public int compareTo(Athlete o) {
        return this.res.compareTo(o.res);
    }

    public String toString() {
        id = String.format("VDV%02d", cnt++);
        return String.format("%s %s %s %s %s %d", id, name, factTime, pre, res, stt);
    }

}
