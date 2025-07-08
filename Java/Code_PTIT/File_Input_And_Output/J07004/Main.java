package Code_PTIT.File_Input_And_Output.J07004;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
//        String Text = "17 20 25 20 15 10 24 17 25 17 22 11 23 18\n" +
//                "14 25 12 10 12 17 21 25";
        Scanner sc = new Scanner(new File("DATA.in"));
        TreeMap<Integer, Integer> map = new TreeMap<>();
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        for (Integer key : map.keySet()) {
            System.out.println(key + " " + map.get(key));
        }
    }
}
