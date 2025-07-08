package Code_PTIT.File_Input_And_Output.J07048;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.File;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SANPHAM.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Items> arr = new ArrayList<>();
        while(n-- > 0) {
            Items items = new Items(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine()), Integer.parseInt(sc.nextLine()));
            arr.add(items);
        }
        Collections.sort(arr);
        for(Items item : arr) System.out.println(item);
    }
}
