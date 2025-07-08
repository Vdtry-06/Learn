package Code_PTIT.Practice.Day1.TH1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double [] a = new double[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextDouble();
        }
        double mi = Double.MAX_VALUE;
        double mx = Double.MIN_VALUE;
        for(double x: a) {
            if(x < mi) mi = x;
            if(x > mx) mx = x;
        }
        double s = 0, cnt = 0;
        for(double x: a) {
            if(x != mi && x != mx) {
                s += x;
                cnt++;
//                System.out.println(x);
            }
        }
        double res = s / cnt;
        System.out.println(String.format("%.2f", res));
    }
}
