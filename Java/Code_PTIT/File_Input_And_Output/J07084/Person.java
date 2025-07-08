package Code_PTIT.File_Input_And_Output.J07084;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class Person implements Comparable<Person> {
    private String name;
    private String startTime;
    private String endTime;
    private long time;

    public Person(String name, String startTime, String endTime) {
        this.name = name;
        this.startTime = startTime;
        this.endTime = endTime;
        time = ProcessTime(startTime, endTime);
    }
    private long ProcessTime(String startTime, String endTime) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        LocalDateTime startDate = LocalDateTime.parse(startTime, dtf);
        LocalDateTime endDate = LocalDateTime.parse(endTime, dtf);

        return ChronoUnit.MINUTES.between(startDate, endDate);
    }

    @Override
    public int compareTo(Person o) {
        return Long.compare(o.time, this.time);
    }

    @Override
    public String toString() {
        return name + " " + time;
    }
}
