package Code_PTIT.Array_Of_Objects.TN02012;

import java.util.ArrayList;

public class Employee {
    private Apartment apartment;
    private String emloyeeId;
    private String name;
    private int salary;
    private int work;

    public Employee(String employeeId, ArrayList<Apartment> apartments, String name, int salary, int work) {
        this.apartment = findEmployeeByApartments(employeeId, apartments);
        this.name = name;
        this.salary = salary;
        this.work = work;
    }

    private Apartment findEmployeeByApartments(String employeeId, ArrayList<Apartment> apartments) {
        for (Apartment apartment : apartments) {
            if(employeeId.substring(3).equals(apartment.getId())) {
                this.emloyeeId = employeeId;
                return apartment;
            }
        }
        return null;
    }
    private long processSalary() {
        String tmp = emloyeeId.substring(0, 1);
        int num = (emloyeeId.charAt(1) - '0') * 10 + emloyeeId.charAt(2) - '0';
        int[][] lookup = {
                {10, 10, 9, 8},
                {12, 11, 10, 9},
                {14, 13, 12, 11},
                {20, 16, 14, 13}
        };
        String group = "ABCD";
        int row, mult = 1;
        if (num >= 1 && num <= 3) row = 0;
        else if (num >= 4 && num <= 8) row = 1;
        else if (num >= 9 && num <= 15) row = 2;
        else row = 3;
        if(tmp.equals("A")) mult = lookup[row][0];
        else if(tmp.equals("B")) mult = lookup[row][1];
        else if(tmp.equals("C")) mult = lookup[row][2];
        else if(tmp.equals("D")) mult = lookup[row][3];
        return salary * work * mult * 1000;
    }

    public String toString() {
        long sumSalary = processSalary();
        return emloyeeId + " " + name + " " + apartment + " " + sumSalary;
    }
}
