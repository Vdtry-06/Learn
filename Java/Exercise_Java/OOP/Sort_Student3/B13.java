package Exercise_Java.OOP.Sort_Student3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Sort_code> lst = new ArrayList<>();
        while(sc.hasNext()){
            lst.add(new Sort_code(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(lst);
        for(Sort_code x : lst){
            System.out.println(x);
        }
    }
}
