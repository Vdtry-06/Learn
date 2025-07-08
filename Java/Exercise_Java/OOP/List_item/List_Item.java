package Exercise_Java.OOP.List_item;

public class List_Item implements Comparable<List_Item>{
    public static int count = 1;
    private String name_item, unit, code;
    private Long sell, buy, bef;
    public List_Item(String name_item, String unit, Long sell, Long buy) {
        this.code = String.valueOf(count);
        while(this.code.length() < 4){
            this.code = "0" + this.code;
        }
        this.code = "MH" + this.code;
        count++;
        this.name_item = name_item;
        this.unit = unit;
        this.sell = sell;
        this.buy = buy;
        this.bef = this.buy - this.sell;
    }
    @Override
    public int compareTo(List_Item o) {
        if(o.bef.equals(this.bef)){
            return this.code.compareTo(o.code);
        }
        return o.bef.compareTo(this.bef);
    }
    @Override
    public String toString() {
        return code + " " + name_item + " " + unit + " " + sell + " " + buy + " " + bef;
    }
}
