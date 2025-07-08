package Exercise_Java.Array.Sang_nto;

import java.util.Scanner;

public class Prime2 {
    public static final int MAX = 1000005;
    public static boolean[] prime = new boolean[MAX];
    public static long[] f = new long[MAX];
    public static void main(String[] args) {
        sang();
        f[0] = 0;
        int cnt = 0;
        for(int i = 1; i <= 1000000; i++){
            if(prime[i]){
                cnt += 1;
            }
            f[i] = cnt;
        }
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if(l == 0) System.out.println(f[r]);
            else System.out.println(f[r] - f[l - 1]);
        }
    }
    public static void sang(){
        for(int i = 0; i <= 1000000; i++){
            prime[i] = true;
        }
        prime[0] = prime[1] = false;
        for(int i = 2; i <= Math.sqrt(1000000); i++){
            if(prime[i])
            {
                for(int j = i * i; j <= 1000000; j += i){
                    prime[j] = false;
                }
            }
        }
    }
}
