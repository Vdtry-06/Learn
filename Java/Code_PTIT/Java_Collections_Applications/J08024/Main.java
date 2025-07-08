package Code_PTIT.Java_Collections_Applications.J08024;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            Queue<String> q = new LinkedList<>();
            q.add("9");
            while (!q.isEmpty()) {
                String s = q.poll();
                long num = Long.parseLong(s);
                if(num % n == 0) {
                    System.out.println(num);
                    break;
                }
                q.add(s + "0");
                q.add(s + "9");
            }
        }
    }
}
