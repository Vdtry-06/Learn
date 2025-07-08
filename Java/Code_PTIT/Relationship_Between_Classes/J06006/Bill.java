package Code_PTIT.Relationship_Between_Classes.J06006;

public class Bill implements Comparable<Bill>{
    private Customer customer;
    private Item item;
    private static int cnt = 1;
    private String id, idCustomer, idItem;
    private int amount, totalPrice, benefit;

    public Bill(Customer customer, Item item, int amount) {
        this.customer = customer;
        this.item = item;
        this.amount = amount;
        this.id = String.format("HD%03d", cnt++);
        totalPrice = item.getSellPrice() * amount;
        benefit = totalPrice - item.getBuyPrice() * amount;
    }
    @Override
    public int compareTo(Bill o) {
        return o.benefit - benefit;
    }
    @Override
    public String toString() {
        return id + " " + customer.toString() + " " + item.toString() + " " + amount + " " + totalPrice + " " + benefit;
    }
}
