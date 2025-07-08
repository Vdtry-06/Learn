package Code_PTIT.Array_Of_Objects.TN02012;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Apartment> apartments = new ArrayList<>();
        while(n-- > 0) {
            apartments.add(new Apartment(sc.next(), sc.nextLine().trim()));
        }
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Employee> employees = new ArrayList<>();
        while(m-- > 0) {
            employees.add(new Employee(sc.nextLine(), apartments, sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        for(Employee e : employees) {
            System.out.println(e);
        }
    }
}
//2
//HC Hanh chinh
//KH Ke hoach Dau tu
//2
//C06HC
//Tran Binh Minh
//65
//25
//D03KH
//Le Hoa Binh
//59
//24