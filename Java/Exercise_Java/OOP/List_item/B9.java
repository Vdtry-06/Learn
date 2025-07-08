package Exercise_Java.OOP.List_item;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<List_Item> lst = new ArrayList<>();
        int n = sc.nextInt();
        sc.nextLine();
        while(n-- != 0){
            lst.add(new List_Item(sc.nextLine(), sc.nextLine(), sc.nextLong(), sc.nextLong()));
            sc.nextLine();
        }
        Collections.sort(lst);
        for(List_Item x : lst){
            System.out.println(x);
        }
    }
}
