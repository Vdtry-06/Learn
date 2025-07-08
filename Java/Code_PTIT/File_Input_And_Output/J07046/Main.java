package Code_PTIT.File_Input_And_Output.J07046;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("KHACH.in"));
        ArrayList<Hotel> hotels = new ArrayList<>();
        int n = sc.nextInt();
        sc.nextLine();
        while(n-- > 0) {
            Hotel hotel = new Hotel(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            hotels.add(hotel);
        }
        Collections.sort(hotels);
        for(Hotel hotel : hotels) { System.out.println(hotel); }
    }
}
