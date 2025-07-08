package Exercise_Java.OOP.wage_Employee;

public class wage_Employee {
    private String name, position, id;
    private long wage_basic, wage_date, wage_month, award, allow, income;

    public wage_Employee(String name, long wage_basic, long wage_date, String position) {
        this.id = "NV01";
        this.name = name;
        this.position = position;
        this.wage_basic = wage_basic;
        this.wage_date = wage_date;
    }
    @Override
    public String toString() {
        switch (position) {
            case "GD" -> allow = 250000;
            case "PGD" -> allow = 200000;
            case "TP" -> allow = 180000;
            case "NV" -> allow = 150000;
        }
        wage_month = wage_basic * wage_date;
        if(wage_date >= 25) award = wage_month * 20 / 100;
        else if(wage_date >= 22) award = wage_month * 10 / 100;
        else award = 0;
        income = wage_month + allow + award;
        return id + " " + name + " " + wage_month + " " + award + " " + allow + " " + income;
    }
}
