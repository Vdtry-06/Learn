package Code_PTIT.File_Input_And_Output.J07011;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner (new File("VANBAN.in"));
        int n = Integer.parseInt(sc.nextLine());
        TreeMap<String, Integer> map = new TreeMap<>();
        while(n-- > 0) {
            String s = sc.nextLine();
            String [] words = s.toLowerCase().split("[^a-z0-9]+");
            for(String word : words) {
               if (!word.isEmpty()) {
                    map.put(word, map.getOrDefault(word, 0) + 1);
                }
            }
//            System.out.println();
        }
        ArrayList<Pair> pairs = new ArrayList<>();
        for(String s : map.keySet()) {
            pairs.add(new Pair(s, map.get(s)));
        }
        Collections.sort(pairs);
        for(Pair p : pairs) {
            System.out.println(p);
        }
    }
}
