package Basic_java.Bai9_Switch_case;

import java.util.Scanner;

public class Switch_case {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = n % 2;
        switch (r)
        {
            case 0:
            System.out.println("Chan");
            break;
            default:// th nguoc lai
            System.out.println("Le");
            break;
        }
    }
}
