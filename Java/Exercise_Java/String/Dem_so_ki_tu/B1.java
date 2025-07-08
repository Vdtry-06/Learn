package Exercise_Java.String.Dem_so_ki_tu;

import java.util.Scanner;

public class B1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int d1 = 0, d2 = 0, d3 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if(Character.isDigit(c)) d2++;
            else if(Character.isLetter(c)) d1++;
            else d3++;
        }
        System.out.print(d1 + " " + d2 + " " + d3);
    }
}
