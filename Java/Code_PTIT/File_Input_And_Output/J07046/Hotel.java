package Code_PTIT.File_Input_And_Output.J07046;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class Hotel implements Comparable<Hotel>{
    private static int cnt = 1;
    private String name;
    private String roomCode;
    private String come;
    private String leave;
    private String code;
    private long between;
    public Hotel(String name, String roomCode, String come, String leave) {
        this.code = String.format("KH%02d", cnt++);
        this.name = name;
        this.roomCode = roomCode;
        this.come = come;
        this.leave = leave;
    }
    public long numberOfDay() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate startDate = LocalDate.parse(this.come, formatter);
        LocalDate endDate = LocalDate.parse(this.leave, formatter);
        this.between = ChronoUnit.DAYS.between(startDate, endDate);
        return this.between;
    }
    @Override
    public int compareTo(Hotel o) {
        return (int) (o.numberOfDay() - this.numberOfDay());
    }
    @Override
    public String toString() {
        return code + " " + name + " " + roomCode + " " + between;
    }
}
