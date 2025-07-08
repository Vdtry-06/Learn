package Code_PTIT.File_Input_And_Output.J07050;

public class Item implements Comparable<Item>{
    private static int cnt = 1;
    private String name, group, code;
    private Float buyPrice, sellPrice, fitness;
    public Item(String name, String group, Float buyPrice, Float sellPrice) {
        this.name = name;
        this.group = group;
        this.buyPrice = buyPrice;
        this.sellPrice = sellPrice;
        this.code = String.format("MH%02d", cnt++);
        this.fitness = sellPrice - buyPrice;
    }
    @Override
    public int compareTo(Item o) {
        return (int) (o.fitness - this.fitness);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + group + " " + String.format("%.2f", fitness);
    }
}
