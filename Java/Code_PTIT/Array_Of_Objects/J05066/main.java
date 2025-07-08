package Code_PTIT.Array_Of_Objects.J05066;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<LookingForStaff> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String [] tmp = sc.nextLine().split(" ");
            String code = tmp[0];
            String name = tmp[1] + " " + tmp[2] + " " + tmp[3];
            arr.add(new LookingForStaff(code, name));
        }

        Collections.sort(arr);

        int m = Integer.parseInt(sc.nextLine());
        for(int i = 0; i < m; i++) {
            String key = sc.nextLine().toLowerCase();
            for(LookingForStaff x : arr) {
                if (x.isContain(key)) {
                    System.out.println(x);
                }
            }
            System.out.println();
        }
    }
}
