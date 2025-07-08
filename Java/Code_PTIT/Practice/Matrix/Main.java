package Code_PTIT.Practice.Matrix;

import java.io.File;
import java.io.FileNotFoundException;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MATRIX.in"));
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            int row = sc.nextInt();
            int col = sc.nextInt();
            int idx_col = sc.nextInt();
            sc.nextLine();
            String[] data = sc.nextLine().split("\\s+");
            int cnt = 0;
            int [][] a = new int[row][col];
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    a[i][j] = Integer.parseInt(data[cnt++]);
                }
            }
            Matrix matrix = new Matrix(row, col, a);
            matrix.Sort(idx_col - 1);
            System.out.println(matrix.toString());
        }

    }
}
