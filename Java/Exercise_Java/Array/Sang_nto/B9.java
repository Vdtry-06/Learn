package Exercise_Java.Array.Sang_nto;

import java.util.Scanner;

public class B9 {
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
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            System.out.println(f[a[i]]);
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
