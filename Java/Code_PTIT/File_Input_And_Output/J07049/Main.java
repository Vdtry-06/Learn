package Code_PTIT.File_Input_And_Output.J07049;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        Scanner sc = new Scanner(new File("MUAHANG.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Item> items = new ArrayList<>();
        while(n-- > 0) {
            items.add(new Item(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine())));
        }
        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Customer> customers = new ArrayList<>();
        while(m-- > 0) {
            customers.add(new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), items, Integer.parseInt(sc.nextLine()), sc.nextLine()));
        }
        Collections.sort(customers);
        for(Customer customer : customers) {
            System.out.println(customer);
        }
    }
}
