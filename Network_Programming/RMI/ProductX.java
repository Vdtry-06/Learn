package RMI;

import java.io.Serializable;

public class ProductX implements Serializable {
    private static final long serialVersionUID = 20171107;
    private String id;
    private String code;
    private String discountCode;
    private int discount;

    public void updateDiscount() {
        int sum = 0;
        for (int i = 0; i < discountCode.length(); i++) {
            if (discountCode.charAt(i) >= '0' && discountCode.charAt(i) <= '9') {
                sum += discountCode.charAt(i) - '0';
            }
        }
        this.discount = sum;
    }
}
