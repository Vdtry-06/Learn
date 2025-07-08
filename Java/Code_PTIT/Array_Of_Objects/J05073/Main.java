package Code_PTIT.Array_Of_Objects.J05073;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Price> prices = new ArrayList<>();
        while(n-- > 0) {
            prices.add(new Price(sc.next(), Integer.parseInt(sc.next()), Integer.parseInt(sc.next())));
        }
        for(Price p : prices) {
            System.out.println(p);
        }
    }
}
//2
//TTVC 400 300
//CCAK 200 200