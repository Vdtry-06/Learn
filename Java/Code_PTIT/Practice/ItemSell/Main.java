package Code_PTIT.Practice.ItemSell;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("KH.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Customer> arrayCustomer = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arrayCustomer.add(new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("MH.in"));
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Item> arrayItem = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            arrayItem.add(new Item(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        sc = new Scanner(new File("HD.in"));
        int q = sc.nextInt();
        ArrayList<Bill> arrayBill = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            String idCustomer = sc.next();
            String idItem = sc.next();
            int quantity = sc.nextInt();
            Customer customer = null;
            Item item = null;
            for (Customer x : arrayCustomer) {
                if (x.getId().equals(idCustomer)) {
                    customer = x;
                    break;
                }
            }
            for (Item x : arrayItem) {
                if (x.getId().equals(idItem)) {
                    item = x;
                    break;
                }
            }
            arrayBill.add(new Bill(customer, item, quantity));
        }
        for (Bill x : arrayBill) {
            System.out.println(x);
        }
    }
}
