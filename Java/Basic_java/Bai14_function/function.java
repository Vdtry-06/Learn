package Basic_java.Bai14_function;

import java.util.Scanner;

public class function {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();
        System.out.println(Cong(x, y, z));
    }
    public static int Cong(int x, int y, int z){
        return x + y + z;
    }
}
