package Exercise_Java.Array.TBC_Nguyen_To;

import java.util.Scanner;

public class B2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int d = 0, s = 0;
        for(int i = 0; i < n; i++) {
            if (prime(a[i])) {
                s += a[i];
                d++;
            }
        }
        double t = (double) s / d;
        System.out.printf("%.3f", t);
    }
    public static boolean prime(int n){
        if(n < 2)
            return false;
        for(int i = 2; i <= Math.sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}
