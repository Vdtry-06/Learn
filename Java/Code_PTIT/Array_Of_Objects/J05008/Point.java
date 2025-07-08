package Code_PTIT.Array_Of_Objects.J05008;

import java.util.ArrayList;

public class Point {
    private Double x;
    private Double y;
    public Point() {}
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Double getX() {return x;}

    public Double getY() {return y;}

    public static double calculatePolygonArea(ArrayList<Point> points) {
        int n = points.size();
        if (n < 3) return 0;
        double area = 0;
        for (int i = 0; i < n; i++) {
            Point current = points.get(i);
            Point next = points.get((i + 1) % n);
            area += current.getX() * next.getY();
            area -= next.getX() * current.getY();
        }
        return Math.abs(area) / 2.0;
    }
}
