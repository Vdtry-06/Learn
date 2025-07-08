package Code_PTIT.Array_Of_Objects.J05006;

public class Employee {
    private String name, sex, date, address, tax, date_sign, id;
    private static int cnt = 1;
    public Employee(String name, String sex, String date, String address, String tax, String date_sign) {
        this.name = name;
        this.sex = sex;
        this.date = date;
        this.address = address;
        this.tax = tax;
        this.date_sign = date_sign;
        this.id = String.format("%05d", cnt++);
    }

    @Override
    public String toString() {
        return id + " " + name + " " + " " + sex + " " + date + " " + address + " " + tax + " " + date_sign;
    }
}
