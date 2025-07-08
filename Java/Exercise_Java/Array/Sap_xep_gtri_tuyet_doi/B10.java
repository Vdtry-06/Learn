package Exercise_Java.Array.Sap_xep_gtri_tuyet_doi;

import java.util.Comparator;
import java.util.Arrays;
import java.util.Scanner;

public class B10 {
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

    static class CustomComparator implements Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b) {
            return Integer.compare(Math.abs(a), Math.abs(b));
        }
    }

}
