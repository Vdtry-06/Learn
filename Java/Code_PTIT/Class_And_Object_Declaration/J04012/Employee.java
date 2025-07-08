package Code_PTIT.Class_And_Object_Declaration.J04012;

public class Employee {
    private String name, position, id;
    private long salaryBasic, cntDay, salaryMonth, reward, allowance, income;


    public Employee(String name, long salaryBasic, long cntDay, String position) {
        this.id = "NV01";
        this.name = name;
        this.salaryBasic = salaryBasic;
        this.cntDay = cntDay;
        this.position = position;
    }

    @Override
    public String toString() {
        if(position.equals("GD")) allowance = 250000;
        else if(position.equals("PGD")) allowance = 200000;
        else if(position.equals("TP")) allowance = 180000;
        else if(position.equals("NV")) allowance = 150000;
        salaryMonth = salaryBasic * cntDay;
        if(cntDay >= 25)  reward = salaryMonth / 5;
        else if(cntDay >= 22) reward = salaryMonth / 10;
        else reward = 0;
        income = salaryMonth + reward + allowance;
        return id + " " + name + " " + salaryMonth + " " + reward + " " + allowance + " " + income;
    }
}
