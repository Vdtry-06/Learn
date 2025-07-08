package Code_PTIT.Practice.ItemSell;

public class Customer {
    private static int cnt = 1;
    private String id, name, sex, date, address;

    public Customer(String name, String sex, String date, String address) {
        this.id = String.format("KH%03d", cnt++);
        this.name = name;
        this.sex = sex;
        this.date = date;
        this.address = address;
    }
    public String getId() {
        return id;
    }
    @Override
    public String toString() {
        return name + " " + address;
    }
}