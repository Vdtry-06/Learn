package Exercise_Java.Array.Can_bang_nto;

import java.util.Scanner;

public class B6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
            int s1 = 0, s2 = 0;
            for(int j = 0; j < i; j++) s1 += a[j];
            for(int j = i + 1; j < n; j++) s2 += a[j];
            if(prime(s1) && prime(s2)){
                System.out.print(i + " ");
            }
        }
    }
    public static boolean prime(int n){
        for(int i = 2; i <= Math.sqrt(n); i++){
            if(n % i == 0){
                return false;
            }
        }
        return n > 2;
    }
}
