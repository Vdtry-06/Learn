package Code_PTIT.Array_Of_Objects.J05081;

public class Items {
    private String id, name, unit;
    private int buy, sell, profit, stt;

    public Items(String name, String unit, int buy, int sell, int stt) {
        this.name = name;
        this.unit = unit;
        this.buy = buy;
        this.sell = sell;
        this.id = "MH001";
        this.stt = stt;
        this.profit = sell - buy;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public int getProfit() {
        return profit;
    }

    public int getStt() {
        return stt;
    }

    @Override
    public String toString() {
        return id + " " + name + " " + unit + " " + buy + " " + sell + " " + profit;
    }
}
