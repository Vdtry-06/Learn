package Code_PTIT.File_Input_And_Output.J07019;

public class Item {
    private String id;
    private String name;
    private int firstPrice;
    private int lastPrice;
    public Item(String id, String name, int firstPrice, int lastPrice) {
        this.id = id;
        this.name = name;
        this.firstPrice = firstPrice;
        this.lastPrice = lastPrice;
    }
    public String getId() {return id;}
    public String getName() {return name;}
    public int getFirstPrice() {return firstPrice;}
    public int getLastPrice() {return lastPrice;}
}
