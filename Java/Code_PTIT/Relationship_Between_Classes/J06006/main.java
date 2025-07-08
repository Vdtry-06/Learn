package Code_PTIT.Relationship_Between_Classes.J06006;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Customer> arrayCustomer = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arrayCustomer.add(new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        int m = sc.nextInt();
        sc.nextLine();
        ArrayList<Item> arrayItem = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            arrayItem.add(new Item(sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
            sc.nextLine();
        }
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
        Collections.sort(arrayBill);
        for (Bill x : arrayBill) {
            System.out.println(x);
        }
    }
}
