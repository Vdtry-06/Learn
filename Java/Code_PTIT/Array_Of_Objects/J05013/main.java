package Code_PTIT.Array_Of_Objects.J05013;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Recruit> arrayRecruit = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            Recruit recruit = new Recruit(sc.nextLine(), sc.nextFloat(), sc.nextFloat());
            sc.nextLine();
            arrayRecruit.add(recruit);
        }
        Collections.sort(arrayRecruit, new Comparator<Recruit>() {
            @Override
            public int compare(Recruit o1, Recruit o2) {
                return o1.getAverage() > o2.getAverage() ? -1 : 1;
            }
        });
        for(Recruit x : arrayRecruit) {
            System.out.println(x);
        }
    }
}
