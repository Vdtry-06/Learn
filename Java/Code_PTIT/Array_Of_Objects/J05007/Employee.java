package Code_PTIT.Array_Of_Objects.J05007;

public class Employee {
    private static int cnt = 1;
    private String name, sex, date, address, tax, contactDate, id;
    private String day, month, year;
    public Employee(String name, String sex, String date, String address, String tax, String contactDate) {
        this.name = name;
        this.sex = sex;
        this.date = date;
        this.address = address;
        this.tax = tax;
        this.contactDate = contactDate;
        this.id = String.format("%05d", cnt++);
        String [] arr = this.date.split("/");
        this.day = arr[0];
        this.month = arr[1];
        this.year = arr[2];

    }
    public String getDay() {
        return day;
    }
    public String getMonth() {
        return month;
    }
    public String getYear() {
        return year;
    }
    @Override
    public String toString() {
        return id + " " + name + " " + sex + " " + date + " " + address + " " + tax + " " + contactDate;
    }
}
