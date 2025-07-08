package Exercise_Java.Array.Mang_2_chieu;

import java.util.Arrays;
import java.util.Scanner;

public class ma_tran_xo_nto {
    public static long[] f = new long[1000005];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int col1 = 0, coln = n - 1, row1 = 0, rown = n - 1;
        int d = 0;
        long[][] a = new long[n][n];
        for(int i = 0; i < n; i++){
            Arrays.fill(a[i], 0);
        }
        process();
        while(d < n * n){
            for(int i = col1; i <= coln; i++){
                a[row1][i] = f[d];
                d++;
            }
            row1++;
            for(int i = row1; i <= rown; i++){
                a[i][coln] = f[d];
                d++;
            }
            coln--;
            for(int i = coln; i >= col1; i--){
                a[rown][i] = f[d];
                d++;
            }
            rown--;
            for(int i = rown; i >= row1; i--){
                a[i][col1] = f[d];
                d++;
            }
            col1++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static boolean prime(int n){
       if(n < 2)
           return false;
       for(int i = 2; i <= Math.sqrt(n); i++){
           if(n % i == 0)
               return false;
       }
       return true;
    }
    public static void process(){
        int cnt = 0;
        for(int i = 2; i <= 1000000; i++){
            if(prime(i)){
                f[cnt] = i;
                cnt++;
            }
        }
    }
}
