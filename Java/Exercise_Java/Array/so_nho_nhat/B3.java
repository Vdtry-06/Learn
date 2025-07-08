package Exercise_Java.Array.so_nho_nhat;

import java.util.Scanner;

public class B3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        int mi = 1000000, d = 0;
        for(int i = 0; i < n; i++) {
            if (a[i] < mi) mi = a[i];
        }
        for(int i = 0; i < n; i++){
            if(a[i] == mi) d++;
        }
        System.out.println(d);
    }
}
