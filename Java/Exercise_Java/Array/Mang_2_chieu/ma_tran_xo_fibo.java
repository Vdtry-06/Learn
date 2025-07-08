package Exercise_Java.Array.Mang_2_chieu;

import java.util.Arrays;
import java.util.Scanner;

public class ma_tran_xo_fibo {
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
        fibo();
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
    public static void fibo(){
        f[0] = 0;
        f[1] = f[2] = 1;
        for(int i = 3; i <= 93; i++){
            f[i] = f[i - 1] + f[i - 2];
        }
    }
}
