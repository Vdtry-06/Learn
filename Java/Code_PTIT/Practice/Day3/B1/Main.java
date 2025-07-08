package Code_PTIT.Practice.Day3.B1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DATA.in"));
        long s = 0;
        while(sc.hasNext()) {
            if(sc.hasNextLong() && !sc.hasNextInt()) {
                long n = sc.nextLong();
                s += n;
            }
            else {
                sc.next();
            }
        }
        System.out.println(s);
    }
}
