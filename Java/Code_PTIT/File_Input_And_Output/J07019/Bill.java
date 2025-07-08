package Code_PTIT.File_Input_And_Output.J07019;


import java.util.ArrayList;

public class Bill {
    private static int cnt = 1;
    private Item item;
    private int quantity;
    private String billCode;
    private long discount;
    private long refund;
    private int price;
    public Bill(String billId, ArrayList<Item> items, int quantity) {
        this.item = findItemIdAndTypeByItem(billId, items);
        this.quantity = quantity;
        this.billCode = item.getId() + billId.substring(2) + String.format("-%03d", cnt++);

        String type = billId.substring(2);
        price = type.equals("1") ? this.item.getFirstPrice() : this.item.getLastPrice();
        refund = quantity * price;
        if(quantity >= 150) discount = Math.round(refund * 0.5);
        else if(quantity >= 100) discount = Math.round(refund * 0.3);
        else if(quantity >= 50) discount = Math.round(refund * 0.15);
        else discount = 0;
        refund = refund - discount;
    }
    private Item findItemIdAndTypeByItem(String billId, ArrayList<Item> items) {
        String itemId = billId.substring(0, 2);
        String type = billId.substring(2);
        for(Item item : items) {
            if(item.getId().equals(itemId)) {
                return item;
            }
        }
        return null;
    }
    @Override
    public String toString() {
        return billCode + " " + item.getName() + " " + discount + " " + refund;
    }
}
