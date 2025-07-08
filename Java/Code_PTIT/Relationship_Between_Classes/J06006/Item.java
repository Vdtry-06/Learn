package Code_PTIT.Relationship_Between_Classes.J06006;

public class Item {
    private static int cnt = 1;
    private String id, name, unit;
    private int buyPrice, sellPrice;

    public Item(String name, String unit, int buyPrice, int sellPrice) {
        this.id = String.format("MH%03d", cnt++);
        this.name = name;
        this.unit = unit;
        this.buyPrice = buyPrice;
        this.sellPrice = sellPrice;
    }

    public String getId() {
        return id;
    }
    public int getSellPrice() {
        return sellPrice;
    }

    public int getBuyPrice() {
        return buyPrice;
    }

    @Override
    public String toString() {
        return name;
    }
}