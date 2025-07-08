package Code_PTIT.File_Input_And_Output.J07002;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DATA.in"));
        int s = 0;
        while(sc.hasNext()) {
            if(sc.hasNextInt()) {
                int n = sc.nextInt();
                s += n;
            }
            else {
                sc.next();
            }
        }
        System.out.println(s);
    }
}
