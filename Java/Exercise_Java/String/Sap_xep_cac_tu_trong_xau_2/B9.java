package Exercise_Java.String.Sap_xep_cac_tu_trong_xau_2;

import java.util.*;

public class B9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] words = s.split("\\s+");
        HashSet<Object> se = new HashSet<>();
        Arrays.sort(words, Comparator.comparingInt(String::length));
        for(String x: words){
            if(reversible(x) && !se.contains(x)){
                System.out.print(x + " ");
                se.add(x);
            }
        }
    }
    public static boolean reversible(String s){
        int n = s.length();
        for(int i = 0; i < n / 2; i++){
            if(s.charAt(i) != s.charAt(n - i - 1)) return false;
        }
        return true;
    }
}
