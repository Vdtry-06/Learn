package Exercise_Java.OOP.Vehicle2;

public class Car extends Vehicle {
    private int horse_power;

    public Car(String code, String name, String brand, String color, int horse_power, int price_buy) {
        super(code, name, brand, color, price_buy);
        this.horse_power = horse_power;
    }

    @Override
    public String toString() {
        return super.toString() + " " + horse_power + " " + getPrice_buy();
    }
}
