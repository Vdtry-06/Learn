package Code_PTIT.Java_Collections_Applications.JKT013;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            Queue<Long> q = new LinkedList<>();
            q.add(6L);
            q.add(8L);
            ArrayList<Long> list = new ArrayList<>();
            while(!q.isEmpty()) {
                long s = q.poll();
                if (s < Math.pow(10, n)) {
                    list.add(s);
                    q.add(s * 10 + 6);
                    q.add(s * 10 + 8);
                } else break;

            }
            list.sort(Collections.reverseOrder());
            System.out.println(list.size());
            for(long s : list) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }
}
