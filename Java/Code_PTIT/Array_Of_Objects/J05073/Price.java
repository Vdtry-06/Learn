package Code_PTIT.Array_Of_Objects.J05073;

import java.io.Serializable;

public class Price implements Serializable {
    private String id;
    private int order;
    private int amount;
    public Price(String id, int order, int amount) {
        this.id = id;
        this.order = order;
        this.amount = amount;
    }

    private float processPrice() {
        float priceItems = order * amount;
        char first = id.charAt(0);
        char last = id.charAt(id.length() - 1);
        if(first == 'T') {
            priceItems = priceItems * (1 + ((last == 'C') ? 0.29f * 0.95f : 0.29f)  + 0.04f);
        }
        else if(first == 'C') {
            priceItems = priceItems * (1 + ((last == 'C') ? 0.1f * 0.95f : 0.1f) + 0.03f);
        }
        else if(first == 'D') {
            priceItems = priceItems * (1 + ((last == 'C') ? 0.08f * 0.95f : 0.08f) + 0.025f);
        }
        else if(first == 'M') {
            priceItems = priceItems * (1 +((last == 'C') ? 0.02f * 0.95f : 0.02f) + 0.005f);
        }
        return priceItems * 1.2f / amount;
    }

    public String toString() {
        float priceItems = processPrice();
        return id + " " + String.format("%.2f", priceItems);
    }
}
