package Code_PTIT.File_Input_And_Output.J07047;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

public class Customer implements Comparable<Customer> ,Serializable {
    private static int cnt = 1;
    private Hottel hottel;
    private String hottelId;
    private String id;
    private String name;
    private String comeDay;
    private String leaveDay;
    private int time;
    private float amountPayable;
    public Customer(String name, String hottelId, ArrayList<Hottel> hottels, String comeDay, String leaveDay) {
        this.id = String.format("KH%02d", cnt++);
        this.name = name;
        this.hottelId = hottelId;
        this.hottel = findHottelIdByHottels(hottelId, hottels);
        this.comeDay = comeDay;
        this.leaveDay = leaveDay;
        this.time = numberOfDays(comeDay, leaveDay);
        this.amountPayable = discount();
    }

    private Hottel findHottelIdByHottels(String hottelId, ArrayList<Hottel> hottels) {
        for (Hottel hottel : hottels) {
            if (hottel.getId().equals(String.valueOf(hottelId.charAt(2)))) {
                return hottel;
            }
        }
        return null;
    }

    private int numberOfDays(String comeDay, String leaveDay) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate come = LocalDate.parse(comeDay, dtf);
        LocalDate leave = LocalDate.parse(leaveDay, dtf);
        return (int) ChronoUnit.DAYS.between(come, leave);
    }

    private float discount() {
        int tmp = time;
        if(time == 0) tmp = 1;
        float amount = tmp * hottel.getPriceDay();
        amount += amount * hottel.getCost();
        if(tmp >= 10 && tmp < 20) amount *= 0.98F;
        else if(tmp >= 20 && tmp < 30) amount *= 0.96F;
        else if(tmp >= 30) amount *= 0.94F;
        return amount;
    }

    public int compareTo(Customer o) {
        return o.time - time;
    }

    public String toString() {
        return id + " " + name + " " + hottelId + " " + time + " " + String.format("%.2f", amountPayable);
    }

}
