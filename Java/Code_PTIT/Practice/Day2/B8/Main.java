package Code_PTIT.Practice.Day2.B8;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DAYSO.in"));
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<BigInteger> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            BigInteger num = new BigInteger(sc.nextLine());
            arr.add(num);
        }
        BigInteger mi = arr.get(0);
        BigInteger mx = arr.get(0);
        BigInteger total = BigInteger.ZERO;
        for(BigInteger x : arr) {
            if(x.compareTo(mi) < 0) {
                mi = x;
            }
            if(x.compareTo(mx) > 0) {
                mx = x;
            }
            total = total.add(x);
        }
        System.out.println(mi);
        System.out.println(mx);
        System.out.println(total);
    }
}
