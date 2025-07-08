package Exercise_Java.String.Ki_tu_xuat_hien_o_ca_2_xau;

import java.util.Scanner;


public class B4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        char[] f = new char[256];
        char[] f2 = new char[256];
        char[] f3 = new char[256];
        char[] f4 = new char[256];
        for(int i = 0; i < s1.length(); i++) {
            char c = s1.charAt(i);
            f[c]++;
            f3[c]++;
        }
        for(int i = 0; i < s2.length(); i++){
            char c = s2.charAt(i);
            f2[c]++;
            f4[c]++;
        }
        for(int i = 0; i < 256; i++){
            if(f[i] != 0 && f2[i] != 0){
                System.out.print((char)i);
                f[i] = 0;
                f2[i] = 0;
            }
        }
        System.out.println();
        for(int i = 0; i < 256; i++){
            if(f3[i] != 0 || f4[i] != 0){
                System.out.print((char)i);
                f3[i] = 0;
                f4[i] = 0;
            }
        }
    }
}
