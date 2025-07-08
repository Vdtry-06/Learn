package Code_PTIT.Java_Collections_Applications.J08015;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            HashMap<Long, Integer> map = new HashMap<>();
            ArrayList<Long> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                arr.add(sc.nextLong());
            }
            long cnt = 0;
            for (int i = 0; i < n; i++) {
                long sub = k - arr.get(i);
                if (map.containsKey(sub)) {
                    cnt += map.get(sub);
//                    System.out.println(map.get(sub) + " " + sub);
                }
                map.put(arr.get(i), map.getOrDefault(arr.get(i), 0) + 1);
            }
            System.out.println(cnt);
        }
    }
}
