package Exercise_Java.Array.Gia_thua_chia_du;

import java.util.Scanner;

public class B8 {
    public static final int MOD = 1000000000 + 7;
    public static long[] f = new long[1000005];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        gt();
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
            System.out.println(f[a[i]]);
        }
    }
    public static void gt(){
        f[0] = 1;
        for(int i = 1; i <= 1000000; i++){
            f[i] = f[i - 1] * i;
            f[i] %= MOD;
        }
    }
}
