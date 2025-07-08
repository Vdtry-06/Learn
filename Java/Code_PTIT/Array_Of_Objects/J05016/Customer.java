package Code_PTIT.Array_Of_Objects.J05016;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class Customer implements Comparable<Customer>, Serializable {
    private static int cnt = 1;
    private String id;
    private String name;
    private int roomNumber;
    private String comeDay;
    private String leavelDay;
    private int priceService;
    private long sumPrice;
    private long time;
    public Customer(String name, int roomNumber, String comeDay, String leavelDay, int priceService) {
        this.id = String.format("KH%02d", cnt++);
        this.name = name;
        this.roomNumber = roomNumber;
        this.comeDay = comeDay;
        this.leavelDay = leavelDay;
        this.priceService = priceService;
        int floor = roomNumber / 100;
        int price = 0;
        if(floor == 1) price = 25;
        else if(floor == 2) price = 34;
        else if(floor == 3) price = 50;
        else if(floor == 4) price = 80;
        this.time = processTime(comeDay, leavelDay);
        this.sumPrice = price * this.time + priceService;
    }

    public long processTime(String comeDay, String leavelDay) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate start = LocalDate.parse(comeDay, dtf);
        LocalDate end = LocalDate.parse(leavelDay, dtf);
        return ChronoUnit.DAYS.between(start, end) + 1;
    }

    public int compareTo(Customer o) {
        return (int) (o.sumPrice - this.sumPrice);
    }

    public String toString() {
        return id + " " + name + " " + roomNumber + " " + time + " " + sumPrice;
    }

}
