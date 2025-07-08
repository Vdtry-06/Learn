package Exercise_Java.String.Tan_suat_tu_trong_xau;

import java.util.*;
import java.util.Map.Entry;

public class B10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] words = s.split("\\s+");
        LinkedHashMap<String, Integer> mp = new LinkedHashMap<>();
        for (String x : words) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        List<Entry<String, Integer>> list = new ArrayList<>(mp.entrySet());
        list.sort(Entry.comparingByKey());
        for(Entry<String, Integer> x : list){
            System.out.println(x.getKey() +  " " + x.getValue());
        }
        System.out.println();
        for(Entry<String, Integer> x: mp.entrySet()){
            System.out.println(x.getKey() + " " + x.getValue());
        }
    }
}
