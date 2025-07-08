package Code_PTIT.Class_And_Object_Declaration.J04015;

public class Teacher {
    private String mgv, name;
    private int salary, step, allowance, income;
    public String getMgv() {
        return mgv;
    }
    public Teacher(String mgv, String name, int salary) {
        this.mgv = mgv;
        this.name = name;
        this.salary = salary;
    }
    @Override
    public String toString() {
        step = Integer.parseInt(getMgv().substring(2, 4));
        String Position = getMgv().substring(0, 2);
        if(Position.equals("HT")) allowance = 2000000;
        else if(Position.equals("HP")) allowance = 900000;
        else if(Position.equals("GV")) allowance = 500000;
        income = salary * step + allowance;
        return mgv + " " + name + " " + step + " " + allowance + " " + income;
    }
}
