package Code_PTIT.File_Input_And_Output.J07020;

import java.util.ArrayList;

public class Bill {
    private static int cnt = 1;
    private Customer customer;
    private Item item;
    private String id;
    private int amount, totalPrice;
    public Bill(String customerId, ArrayList<Customer> customers, String itemId, ArrayList<Item> items, int amount) {
        this.customer = findCustomerIdByCustomers(customerId, customers);
        this.item = findItemIdByItems(itemId, items);
        this.amount = amount;
        this.id = String.format("HD%03d", cnt++);
        totalPrice = this.item.getSell() * amount;
    }
    private Customer findCustomerIdByCustomers(String customerId, ArrayList<Customer> customers) {
        for(Customer customer : customers) {
            if(customerId.equals(customer.getId())) {
                return customer;
            }
        }
        return null;
    }
    private Item findItemIdByItems(String itemId, ArrayList<Item> items) {
        for(Item item : items) {
            if(itemId.equals(item.getId())) {
                return item;
            }
        }
        return null;
    }
    @Override
    public String toString() {
        return id + " " + customer.toString() + " " + item.toString() + " " + amount + " " + totalPrice;
    }
}
