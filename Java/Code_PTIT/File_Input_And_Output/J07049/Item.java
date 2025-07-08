package Code_PTIT.File_Input_And_Output.J07049;

public class Item {
    private String code;
    private String name;
    private int price;
    private int warranty;
    public Item(String code, String name, int price, int warranty) {
        this.code = code;
        this.name = name;
        this.price = price;
        this.warranty = warranty;
    }
    public String getCode() {
        return code;
    }
    public int getPrice() {
        return price;
    }
    public int getWarranty() {
        return warranty;
    }
}
