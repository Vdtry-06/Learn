package Code_PTIT.Practice.ItemSell;

public class Bill{
    private Customer customer;
    private Item item;
    private static int cnt = 1;
    private String id, idCustomer, idItem;
    private int amount, totalPrice;

    public Bill(Customer customer, Item item, int amount) {
        this.customer = customer;
        this.item = item;
        this.amount = amount;
        this.id = String.format("HD%03d", cnt++);
        totalPrice = item.getSellPrice() * amount;
    }
    @Override
    public String toString() {
        return id + " " + customer.toString() + " " + item.toString() + " " + amount + " " + totalPrice;
    }
}
