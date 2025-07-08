package Code_PTIT.Practice.Day2.B1;

import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        TreeSet<Integer> sa = new TreeSet<>();
        TreeSet<Integer> sb = new TreeSet<>();
        for(int i = 0; i < n; i++){
            sa.add(sc.nextInt());
        }
        for(int i = 0; i < m; i++){
            sb.add(sc.nextInt());
        }
        TreeSet<Integer> giao = new TreeSet<>(sa);
        giao.retainAll(sb);
        for(int x:giao) {
            System.out.printf(x + " ");
        }
        System.out.println();
        for(Integer x:sa){
            if(!sb.contains(x)){
                System.out.printf(x + " ");
            }
        }
        System.out.println();
        for(Integer x:sb){
            if(!sa.contains(x)){
                System.out.printf(x + " ");
            }
        }
        System.out.println();
    }
}
