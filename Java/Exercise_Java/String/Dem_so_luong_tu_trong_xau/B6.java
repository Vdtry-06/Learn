package Exercise_Java.String.Dem_so_luong_tu_trong_xau;

import java.util.Scanner;

public class B6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] word = s.split("\\s+");
        System.out.println(word.length);
    }
}
