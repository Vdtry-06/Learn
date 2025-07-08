package Exercise_Java.Array.dem_tong_chan_le;

import java.util.Scanner;

public class B1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        int d1 = 0, d2 = 0, s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0) {
                d1++;
                s1 += a[i];
            }
            else{
                d2++;
                s2 += a[i];
            }
        }
        System.out.println(d1 + "\n" + d2 + "\n" + s1 + "\n" + s2);
    }
}
