package Code_PTIT.Array_Of_Objects.J05071;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Local> locals = new ArrayList<>();
        while(n-- > 0) {
            locals.add(new Local(sc.nextLine(), sc.nextLine(), Integer.parseInt(sc.nextLine())));
        }

        int m = Integer.parseInt(sc.nextLine());
        ArrayList<Call> calls = new ArrayList<>();
        while(m-- > 0) {
            calls.add(new Call(sc.next(), sc.next(), sc.next(), locals));
        }

        for(Call call : calls) {
            System.out.println(call);
        }
    }
}
//2
//53
//Da Nang
//3000
//64
//Vung Tau
//1000
//3
//064-824531 11:20 11:22
//8293567 09:07 09:15
//053-823532 12:00 12:05