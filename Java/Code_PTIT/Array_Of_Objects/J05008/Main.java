package Code_PTIT.Array_Of_Objects.J05008;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            ArrayList<Point> points = new ArrayList<>();

            while(n-- > 0) {
                double x = sc.nextDouble();
                double y = sc.nextDouble();
                points.add(new Point(x, y));
            }

            System.out.printf("%.3f\n", Point.calculatePolygonArea(points));
        }

    }
}
//2
//3
//0 0
//1 0
//0 1
//4
//0 0
//2 0
//2 2
//0 2