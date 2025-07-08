package Exercise_Java.Array.Mang_2_chieu;

import java.util.Scanner;

public class Tong_hang_Tong_cot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < n; i++){
            long s = 0;
            for(int j = 0; j < m; j++){
                s += a[i][j];
            }
            System.out.print(s + " ");
        }
        System.out.println();
        for(int j = 0; j < m; j++){
            long s1 = 0;
            for(int i = 0; i < n; i++){
                s1 += a[i][j];
            }
            System.out.print(s1 + " ");
        }
    }
}
