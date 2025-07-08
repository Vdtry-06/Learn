package Exercise_Java.OOP.Vehicle;

public class Vehicle_together implements Comparable<Vehicle_together>{
    private String code, name, brand, color;
    private int price_buy;

    public Vehicle_together(String code, String name, String brand, String color, int price_buy) {
        this.code = code;
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.price_buy = price_buy;
    }

    @Override
    public int compareTo(Vehicle_together o) {
        if(getPrice_buy() == o.getPrice_buy()){
            return this.code.compareTo(o.code);
        }
        return Integer.compare(o.getPrice_buy(), getPrice_buy());
    }
    @Override
    public String toString() {
        return code + " " + name + " " + brand + " " + color;
    }

    public String getBrand() {
        return brand;
    }

    public int getPrice_buy() {
        return price_buy;
    }
}
