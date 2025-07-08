package Exercise_Java.String.Tan_suat_xuat_hien_ki_tu;

import java.util.Scanner;

public class B2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] f = new int[256];
        int[] f2 = new int[256];
        char c;

        for(int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            f[c]++;
        }
        
        for(int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            f2[c]++;
        }
        
        for(int i = 0; i < 256; i++) {
            if (f[i] != 0) {
                System.out.println((char) i + " " + f[i]);
                f[i] = 0;
            }
        }

        System.out.println();

        for(int i = 0; i < s.length(); i++) {
            c = s.charAt(i);
            if (f2[c] != 0) {
                System.out.println(c + " " + f2[c]);
                f2[c] = 0;
            }
        }
    }
}
