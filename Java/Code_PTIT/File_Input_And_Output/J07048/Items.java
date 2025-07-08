package Code_PTIT.File_Input_And_Output.J07048;

public class Items implements Comparable<Items>{
    private String code, name;
    private Integer price, limited;
    public Items(String code, String name, Integer price, Integer limited) {
        this.code = code;
        this.name = name;
        this.price = price;
        this.limited = limited;
    }
    @Override
    public int compareTo(Items o) {
        if(this.price.compareTo(o.price) == 0) {
            return this.code.compareTo(o.code);
        }
        return (int) (o.price - this.price);
    }
    @Override
    public String toString() {
        return code + " " + name + " " + price + " " + limited;
    }
}
