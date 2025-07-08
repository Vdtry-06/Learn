package Code_PTIT.Practice.Day2.B4;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        ArrayList<Pair<Integer, Integer>> edge = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1 && i < j) {
                    edge.add(new Pair<>(i + 1, j + 1));
                }
            }
        }
        for(Pair<Integer, Integer> p : edge) {
            System.out.println(p);
        }
    }
}
