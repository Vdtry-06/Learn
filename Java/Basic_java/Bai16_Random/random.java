package Basic_java.Bai16_Random;

import java.util.Random;

public class random {
    public static void main(String[] args) {
        Random rd = new Random();
        
        // 1. lay ngau nhien 1 so nguyen
        int soNguyen = rd.nextInt(-100,100);
        System.out.println(soNguyen);
    }
}
