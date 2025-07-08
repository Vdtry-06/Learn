package Exercise_Java.OOP.Vehicle2;


public class Vehicle {
    private String code, name, brand, color;
    private int price_buy;

    public Vehicle(String code, String name, String brand, String color, int price_buy) {
        this.code = code;
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.price_buy = price_buy;
    }

    @Override
    public String toString() {
        return code + " " + name + " " + brand + " " + color;
    }

    public int getPrice_buy() {
        return price_buy;
    }
}
