package Exercise_Java.String.Tap_tu_chung;

import java.util.*;

public class B13_c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        String[] S1 = s1.toLowerCase().split("\\s+");
        String[] S2 = s2.toLowerCase().split("\\s+");
        HashSet<String> se = new HashSet<>(Arrays.asList(S1));
        ArrayList<String> t = new ArrayList<>();
        for(String x: S2){
            if(se.contains(x)){
                t.add(x);
                se.remove(x);
            }
        }
        Collections.sort(t);
        for(String x: t){
            System.out.print(x + " ");
        }
    }
}
