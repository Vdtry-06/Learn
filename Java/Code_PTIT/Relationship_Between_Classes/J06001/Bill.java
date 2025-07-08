package Code_PTIT.Relationship_Between_Classes.J06001;

import java.util.ArrayList;

public class Bill {
    private static int cnt = 1;
    private Product product;
    private int amount;
    private String productId;
    private String type;
    private String id;
    private int price, discount, sum;

    public Bill(String productId, int amount, ArrayList<Product> products) {
        this.productId = productId;
        this.id = productId.substring(0, 2);
        this.type = productId.substring(2);
        this.product = findProductIdByProducts(id, products);
        this.amount = amount;
        if(this.type.equals("1")) {
//            assert this.product != null;
            this.price = this.product.getPrice1() * amount;
        }
        else if(this.type.equals("2")) {
//            assert this.product != null;
            this.price = this.product.getPrice2() * amount;
        }
        this.discount = 0;
        if(amount >= 150) this.discount = this.price / 2;
        else if(amount >= 100) this.discount = this.price * 3 / 10;
        else if(amount >= 50) this.discount = this.price * 15 / 100;
        this.sum = this.price - this.discount;
    }

    private Product findProductIdByProducts(String id, ArrayList<Product> products) {
        for (Product product : products) {
            if(id.equals(product.getId())) {
                return product;
            }
        }
        return null;
    }

    public String toString() {
        String ma = productId + String.format("-%03d", cnt++);
        return ma + " " + product + " " + discount + " " + sum;
    }

}
