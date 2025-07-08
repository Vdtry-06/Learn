package Code_PTIT.Array_Of_Objects.J05081;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Items> arrayItem = new ArrayList<>();
        for(int i = 1; i <= n; ++i) {
            sc.nextLine();
            Items items = new Items(sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt(), i);
            items.setId("MH" + String.format("%03d", i));
            arrayItem.add(items);
        }
        Collections.sort(arrayItem, new Comparator<Items>() {
            @Override
            public int compare(Items o1, Items o2) {
                if(o1.getProfit() != o2.getProfit()) return o2.getProfit() - o1.getProfit();
                return o1.getStt() - o2.getStt();
            }
        });
        for(Items x : arrayItem) {
            System.out.println(x.toString());
        }
    }
}
