package Code_PTIT.Practice.Day1.TH3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "12 3 4 5 6 7\n" +
//                "123243434354546\n" +
//                "Aaa 1 1 Bbb XXX yyy 5 5 dsfrgrt3\n" +
//                "45646szdfse545\n" +
//                "44444444444444\n" +
//                "999999999999999999999999999 \n" +
//                "9876543456\n" +
//                "9";
//        Scanner sc = new Scanner(Text);
        Scanner sc = new Scanner(new File("DATA.in"));
        long sum = 0;
        while(sc.hasNext()){
            if(sc.hasNextLong()) {
                long n = sc.nextLong();
                if(n > Integer.MAX_VALUE) {
                    sum += n;
                }
            } else {
                sc.next();
            }
        }
        System.out.println(sum);
    }
}
