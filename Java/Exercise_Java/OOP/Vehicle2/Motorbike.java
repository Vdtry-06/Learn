package Exercise_Java.OOP.Vehicle2;

public class Motorbike extends Vehicle{
    private int speend;

    public Motorbike(String code, String name, String brand, String color, int speend, int price_buy) {
        super(code, name, brand, color, price_buy);
        this.speend = speend;
    }

    @Override
    public String toString() {
        return super.toString() + " " + speend + " " + getPrice_buy();
    }
}
