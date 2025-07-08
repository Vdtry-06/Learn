package Code_PTIT.Array_Of_Objects.J05016;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Customer> customers = new ArrayList<>();
        while(n-- > 0) {
            customers.add(new Customer(sc.nextLine().trim(), Integer.parseInt(sc.nextLine().trim()), sc.nextLine().trim(), sc.nextLine().trim(), Integer.parseInt(sc.nextLine().trim())));
        }
        Collections.sort(customers);
        for(Customer c : customers) {
            System.out.println(c);
        }
    }
}
//3
//Huynh Van Thanh
//103
//05/06/2010
//05/06/2010
//15
//Le Duc Cong
//106
//08/03/2010
//01/05/2010
//220
//Tran Thi Bich Tuyen
//207
//10/04/2010
//21/04/2010
//96