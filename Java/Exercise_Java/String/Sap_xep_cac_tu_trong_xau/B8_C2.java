package Exercise_Java.String.Sap_xep_cac_tu_trong_xau;

import java.util.*;

public class B8_C2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] t = s.split("\\s+");
        Arrays.sort(t);
        for(String x : t) {
            System.out.print(x + " ");
        }
        System.out.println();
        Arrays.sort(t, new CustomComparator());
        for(String x : t) {
            System.out.print(x + " ");
        }
    }
    static class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b){
            if(a.length() == b.length())
                return a.compareTo(b);
            return Integer.compare(a.length(), b.length());
        }
    }
}
