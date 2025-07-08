package Code_PTIT.File_Input_And_Output.J07047;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        ArrayList<Hottel> hottels = new ArrayList<>();
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0 ) {
            hottels.add(new Hottel(sc.next(), sc.next(), Integer.parseInt(sc.next()), Float.parseFloat(sc.nextLine().trim())));
        }
        ArrayList<Customer> customers = new ArrayList<>();
        int m = Integer.parseInt(sc.nextLine());
        while(m-- > 0 ) {
            customers.add(new Customer(sc.nextLine(), sc.nextLine(), hottels, sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(customers);
        for (Customer c : customers) {
            System.out.println(c);
        }
    }

}
