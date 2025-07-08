package Code_PTIT.File_Input_And_Output.J07051;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class Hotel implements Comparable<Hotel>{
    private static int cnt = 1;
    private String code, name, checkIn, checkOut;
    private Integer numberOfRoom, price, service;
    private long between, frais;
    public Hotel(String name, Integer numberOfRoom, String checkIn, String checkOut, Integer service) throws ParseException {
        this.code = String.format("KH%02d", cnt++);
        this.name = name.trim().toLowerCase();
        this.numberOfRoom = numberOfRoom;
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        this.checkIn = sdf.format(sdf.parse(checkIn.trim()));
        this.checkOut = sdf.format(sdf.parse(checkOut.trim()));
        this.service = service;
        int floor = numberOfRoom / 100;
        if (floor == 1) this.price = 25;
        else if(floor == 2) this.price = 34;
        else if(floor == 3) this.price = 50;
        else this.price = 80;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate startDate = LocalDate.parse(this.checkIn, formatter);
        LocalDate endDate = LocalDate.parse(this.checkOut, formatter);
        this.between = ChronoUnit.DAYS.between(startDate, endDate) + 1;
        this.frais = priceOfDay();
    }
    public String getName() {
        String [] parts = name.split("\\s+");
        StringBuilder res = new StringBuilder();
        for(String part: parts) {
            res.append(Character.toUpperCase(part.charAt(0))).append(part.substring(1)).append(" ");
        }
        res.deleteCharAt(res.length() - 1);
        return res.toString();
    }
    public long priceOfDay() {
        return this.between * this.price + this.service;
    }
    @Override
    public int compareTo(Hotel o) {
        return Long.compare(o.priceOfDay(), this.priceOfDay());
    }
    @Override
    public String toString() {
        return code + " " + getName() + " " + numberOfRoom + " " +  between + " " + frais;
    }
}
