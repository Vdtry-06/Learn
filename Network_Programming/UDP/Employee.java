package UDP;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Employee implements Serializable {
    private static final long serialVersionUID = 20261107L;
    private String id;
    private String name;
    private double salary;
    private String hireDate;

    public Employee(String id, String name, double salary, String hireDate) {
        this.id = id;
        this.name = name;
        this.salary = salary;
        this.hireDate = hireDate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        String[] parts = name.split(" ");
        String newName = "";
        for (String s : parts) {
            newName += s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase() + " ";
        }
        newName = newName.substring(0, newName.length() - 1);
        this.name = newName;
        System.out.println(newName);
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        String year = hireDate.substring(0, 4);
        int x = 0;
        for (int i = 0; i < year.length(); i++) {
            x += year.charAt(i) - '0';
        }
        salary = Double.parseDouble(String.format("%.2f", salary * (1 + (double) x / 100)));
        this.salary = salary;
        System.out.println(salary);
    }

    public String getHireDate() {
        return hireDate;
    }

    public void setHireDate(String hireDate) {
        DateTimeFormatter in = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        DateTimeFormatter out = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate date = LocalDate.parse(hireDate, in);
        String formatDate = date.format(out);
        this.hireDate = formatDate;
        System.out.println(formatDate);
    }
}
