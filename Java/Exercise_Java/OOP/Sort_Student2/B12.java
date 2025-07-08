package Exercise_Java.OOP.Sort_Student2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Sort_Class> lst = new ArrayList<>();
        while(n-- != 0){
            lst.add(new Sort_Class(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(lst);
        for(Sort_Class x : lst){
            System.out.println(x);
        }
    }
}
