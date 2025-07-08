package Code_PTIT.File_Input_And_Output.J07047;

public class Hottel {
    private String id;
    private String name;
    private int priceDay;
    private float cost;
    public Hottel(String id, String name, int priceDay, float cost) {
        this.id = id;
        this.name = name;
        this.priceDay = priceDay;
        this.cost = cost;
    }
    public String getId() {return id;}
    public int getPriceDay() {return priceDay;}
    public float getCost() {return cost;}
}
