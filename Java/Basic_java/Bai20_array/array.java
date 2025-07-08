package Basic_java.Bai20_array;

import java.util.Arrays;
import java.util.Scanner;

public class array {
    public static void main(String[] args) {
        // // khai bao mang
        // String [] mangStr;
        // Float [] mangfl;
        // Double [] mangdb;

        // // khoi tao mang kem theo kich thuoc
        // String [] mangStr2 = new String[12]; // chua toi da 12 phan tu
        // int [] mangNguyen2 = new int[7];

        // // khoi tao mang kem gia tri ban dau
        // String  [] mangStr3 = new String[]{"Chi pheo", "Thi no", "Ong giao"};
        // int []mangNguyen3 = new int[]{1, 2, 3, 4, 5, 6, 7};

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        
        System.out.println(Arrays.toString(a));

        // clone:
        int [] mang12 = {1, 2, 3, 4, 5, 6};
        int [] mang13 = mang12.clone();
        mang12[0] = 2;
        System.out.println(Arrays.toString(mang12));
        System.out.println(Arrays.toString(mang13));
    }
}
