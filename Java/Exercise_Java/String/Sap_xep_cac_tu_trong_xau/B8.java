package Exercise_Java.String.Sap_xep_cac_tu_trong_xau;

import java.util.*;

public class B8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        String[] words = S.split("\\s+");
        Arrays.sort(words);
        System.out.println(String.join(" ", words));
        Arrays.sort(words, Comparator.comparingInt(String::length));
        System.out.println(String.join(" ", words));
    }
}
