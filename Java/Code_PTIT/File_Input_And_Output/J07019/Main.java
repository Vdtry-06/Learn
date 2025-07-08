package Code_PTIT.File_Input_And_Output.J07019;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DATA1.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Item> items = new ArrayList<>();
        while(n-- > 0) {
            items.add(new Item(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("DATA2.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Bill> bills = new ArrayList<>();
        while(m-- > 0) {
            bills.add(new Bill(sc.next(), items, Integer.parseInt(sc.next())));
        }
        for(Bill bill : bills) {
            System.out.println(bill);
        }
    }
}
