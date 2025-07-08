package Exercise_Java.Array.Tim_kiem_nhi_phan;

import java.util.Arrays;
import java.util.Scanner;

public class B12 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int m = sc.nextInt();
        while(m-- != 0){
            int x = sc.nextInt();
            if(find(a, n, x)) System.out.println("YES");
            else System.out.println("NO");
        }
    }
    public static boolean find(int[] a, int n, int x){
        int l = 0, r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(a[m] == x) return true;
            else if(a[m] < x) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
}
