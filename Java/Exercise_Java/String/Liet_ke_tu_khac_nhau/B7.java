package Exercise_Java.String.Liet_ke_tu_khac_nhau;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        HashSet<String> se = new HashSet<>();
        String[] word = s.split("\\s+");
        String[] t = word.clone();

        Arrays.sort(t);
        for(int i = 0; i < t.length; i++){
            if(!se.contains(t[i])){
                System.out.print(t[i] + " ");
                se.add(t[i]);
            }
        }
        System.out.println();
        se.clear();
        for(int i = 0; i < word.length; i++){
            if(!se.contains(word[i])){
                System.out.print(word[i] + " ");
                se.add(word[i]);
            }
        }
    }
}
