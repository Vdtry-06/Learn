package Code_PTIT.File_Input_And_Output.J07050;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MATHANG.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Item> arr = new ArrayList<>();
        while(n-- > 0) {
            Item item = new Item(sc.nextLine(), sc.nextLine(), Float.parseFloat(sc.nextLine()), Float.parseFloat(sc.nextLine()));
            arr.add(item);
        }
        Collections.sort(arr);
        for(Item x : arr) System.out.println(x);
    }
}
