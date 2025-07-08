package Exercise_Java.Array.Sap_xep_theo_tong_cso;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class B11 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] a = new Integer[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a, new CustomComparator());
        for(int i = 0; i < n; i++){
            System.out.print(a[i] + " ");
        }
    }
    public static int sum(int n){
        int s = 0;
        while(n != 0){
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    static class CustomComparator implements Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b){
            if(sum(a) == sum(b)){
                return Integer.compare(a, b);
            }
            return Integer.compare(sum(a), sum(b));
        }
    }
}
