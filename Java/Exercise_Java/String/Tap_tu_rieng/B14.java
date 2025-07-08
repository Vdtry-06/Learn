package Exercise_Java.String.Tap_tu_rieng;

import java.util.*;

public class B14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        String[] S1 = s1.toLowerCase().split("\\s+");
        String[] S2 = s2.toLowerCase().split("\\s+");
        Arrays.sort(S1);
        HashSet<String> se = new HashSet<>(Arrays.asList(S2));
        ArrayList<String> t = new ArrayList<>();
        for(String x: S1){
            if(!se.contains(x)){
                System.out.print(x + " ");
                se.add(x);
            }
        }
    }
}
