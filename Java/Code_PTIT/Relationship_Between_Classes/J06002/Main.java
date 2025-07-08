package Code_PTIT.Relationship_Between_Classes.J06002;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Product> products = new ArrayList<>();
        while(n-- > 0) {
            products.add(new Product(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Bill> bills = new ArrayList<>();
        while(m-- > 0) {
            bills.add(new Bill(sc.next(), Integer.parseInt(sc.next()), products));
        }
        Collections.sort(bills);
        for(Bill bill : bills) {
            System.out.println(bill);
        }
    }
}
//2
//AT
//Ao thun
//80000
//45000
//QJ
//Quan Jean
//220000
//125000
//2
//AT1 95
//QJ2 105