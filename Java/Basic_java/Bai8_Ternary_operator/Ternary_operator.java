package Basic_java.Bai8_Ternary_operator;

import java.util.Scanner;

public class Ternary_operator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println(x % 2 == 0 ? "Chan" : "Le");
    }
}
