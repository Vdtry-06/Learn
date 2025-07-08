package Code_PTIT.File_Input_And_Output.J07049;

import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class Customer implements Comparable<Customer> {
    private static int cnt = 1;
    private String id;
    private String name;
    private String address;
    private Item item;
    private int quantity;
    private int total;
    private String boughtDay;
    private String expiryDate;
    public Customer(String name, String address, String itemId, ArrayList<Item> items, int quantity, String boughtDay) throws ParseException {
        this.id = String.format("KH%02d", cnt++);
        this.name = name;
        this.address = address;
        this.item = findItemIdByItems(itemId, items);
        this.quantity = quantity;
        this.boughtDay = boughtDay;
        this.expiryDate = ProcessDay();
        this.total = ProcessMoney();
    }
    private Item findItemIdByItems(String itemId, ArrayList<Item> items) {
        for (Item item : items) {
            if(item.getCode().equals(itemId)){
                return item;
            }
        }
        return null;
    }
    private String ProcessDay() throws ParseException {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate startDate = LocalDate.parse(this.boughtDay, dtf);
        LocalDate endDate = startDate.plusMonths(item.getWarranty());
        return endDate.format(dtf);
    }
    private int ProcessMoney() {
        return this.item != null ? item.getPrice() * this.quantity : 0;
    }
    @Override
    public int compareTo(Customer o) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate thisExpiry = LocalDate.parse(this.expiryDate, dtf);
        LocalDate otherExpiry = LocalDate.parse(o.expiryDate, dtf);

        if(thisExpiry.equals(otherExpiry)){
            return this.id.compareTo(o.id);
        }
        return thisExpiry.compareTo(otherExpiry);
    }
    @Override
    public String toString() {
        return id + " " + name + " " + address + " " + item.getCode() + " " + total + " " + expiryDate;
    }
}
