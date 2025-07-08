package Code_PTIT.File_Input_And_Output.J07020;

public class Item {
    private static int cnt = 1;
    private String id;
    private String name;
    private String unit;
    private int buy;
    private int sell;
    public Item(String name, String unit, int buy, int sell) {
        this.id = String.format("MH%03d", cnt++);
        this.name = name;
        this.unit = unit;
        this.buy = buy;
        this.sell = sell;
    }
    public String getId() {
        return id;
    }
    public int getSell() { return sell; }
    @Override
    public String toString() {
        return name + " " + unit + " " + buy + " " + sell;
    }
}
