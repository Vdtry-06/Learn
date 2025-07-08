package Code_PTIT.File_Input_And_Output.J07025;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        Scanner sc = new Scanner(new File("KHACHHANG.in"));
        ArrayList<Customer> arr = new ArrayList<>();
        int n = Integer.parseInt(sc.nextLine());
        while(n-- > 0) {
            Customer customer = new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            arr.add(customer);
        }
        Collections.sort(arr);
        for(Customer c : arr) {
            System.out.println(c);
        }
    }
}
