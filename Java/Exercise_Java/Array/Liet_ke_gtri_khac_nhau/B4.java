package Exercise_Java.Array.Liet_ke_gtri_khac_nhau;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        Set<Integer> se = new HashSet<>();
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
            if(!se.contains(a[i])){
                System.out.print(a[i] + " ");
                se.add(a[i]);
            }
        }
    }
}
