package Exercise_Java.Array.Liet_ke_va_dem_fibo;

import java.util.Scanner;

public class B7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }
        boolean check = true;
        for (int i = 0; i < n; i++) {
            if (isFibonacci(a[i])) {
                check = false;
                System.out.print(a[i] + " ");
            }
        }
        if (check) {
            System.out.print("NONE");
        }
    }
    public static boolean isFibonacci(long n) {
        if (n == 0 || n == 1) {
            return true;
        }
        long a = 0, b = 1;
        while (b <= n) {
            if (b == n) {
                return true;
            }
            long temp = a + b;
            a = b;
            b = temp;
        }
        return false;
    }
}
