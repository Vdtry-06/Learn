package Exercise_Java.OOP.Class_phanso;

import java.util.Scanner;

public class B3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tu = sc.nextInt();
        int mau = sc.nextInt();
        PhanSo a = new PhanSo(tu, mau);
        a.process();
        System.out.println(a);
    }
}
