package Exercise_Java.String.Xau_doi_xung;

import java.util.Scanner;

public class B5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(DX(s) ? "YES" : "NO");
    }
    public static boolean DX(String s){
        int n = s.length();
        for(int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) return false;
        }
        return true;
    }
}
