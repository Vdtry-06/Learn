package Exercise_Java.String.Ghep_xau;

import java.util.*;

public class Ghep_xau {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        String[] str = s.split(" ");
        Arrays.sort(str, (a, b) -> (b + a).compareTo(a + b));
        StringBuilder res = new StringBuilder();
        for(String x: str){
            res.append(x);
        }
        System.out.println(res.toString());
    }
}
