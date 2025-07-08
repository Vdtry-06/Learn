package Code_PTIT.File_Input_And_Output.J07020;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("KH.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Customer> customers = new ArrayList<>();
        while (n-- > 0) {
            customers.add(new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("MH.in"));
        ArrayList<Item> items = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        while (m-- > 0) {
            items.add(new Item(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()),Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("HD.in"));
        int q = Integer.parseInt(sc.nextLine());
        ArrayList<Bill> bills = new ArrayList<>();
        while (q-- > 0) {
            bills.add(new Bill(sc.next(), customers, sc.next(), items, Integer.parseInt(sc.next())));
        }
        for (Bill bill : bills) {
            System.out.println(bill);
        }
    }
}
